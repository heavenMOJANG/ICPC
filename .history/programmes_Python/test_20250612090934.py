import pandas as pd
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

# 读取原始数据
df = pd.read_csv("greenhouse_raw_data.csv", parse_dates=['timestamp'])

# 设置时间为索引
df.set_index('timestamp', inplace=True)

# 重采样为每分钟数据，确保时间对齐
df = df.resample('1T').mean()

# ---------- 缺失值处理 ----------
# 使用前向填充 + 后向填充补齐缺失值
df.ffill(inplace=True)
df.bfill(inplace=True)

# ---------- 异常值处理 ----------
def remove_outliers_zscore(series, threshold=3):
    z_scores = np.abs(stats.zscore(series, nan_policy='omit'))
    return series.mask(z_scores > threshold)

# 对每个参数进行异常值检测与处理
df['temperature'] = remove_outliers_zscore(df['temperature']).interpolate()
df['humidity'] = remove_outliers_zscore(df['humidity']).interpolate()
df['co2'] = remove_outliers_zscore(df['co2']).interpolate()
df['light'] = remove_outliers_zscore(df['light']).interpolate()

# ---------- 单位标准化 ----------
# 光照取对数处理，避免极端值影响
df['light_log'] = np.log10(df['light'].clip(lower=1))  # 避免log(0)

# ---------- 平滑滤波（滑动平均） ----------
df['temperature_smooth'] = df['temperature'].rolling(window=5, center=True).mean()
df['humidity_smooth'] = df['humidity'].rolling(window=5, center=True).mean()
df['co2_smooth'] = df['co2'].rolling(window=5, center=True).mean()
df['light_smooth'] = df['light_log'].rolling(window=5, center=True).mean()

# ---------- 结果保存 ----------
df_cleaned = df[['temperature_smooth', 'humidity_smooth', 'co2_smooth', 'light_smooth']]
df_cleaned.columns = ['temperature', 'humidity', 'co2', 'light_log']
df_cleaned.dropna().to_csv("greenhouse_cleaned_data.csv")

# ---------- 可选：绘图查看处理效果 ----------
df[['temperature', 'temperature_smooth']].plot(title='Temperature (Raw vs Smoothed)')
plt.show()