package exercise;

import java.util.*;

public class SegmentTree {//区间加法线段树
	private static final int N = 1000010;
	private int[] tree = new int[N << 2];
	private int[] addTag = new int[N << 2];
	private int arrayLength = 0;
	private ArrayList<Integer> array = new ArrayList<Integer>();
	
	public SegmentTree(ArrayList<Integer> nums) {//线段树类初始化
		this.array = nums;
		this.arrayLength = array.size() - 1;
		build(1, arrayLength, 1);
	}
	
	private void pushUp(int p){
		tree[p] = tree[p << 1] + tree[p << 1 | 1];//子结点的值上传
	}
	
	private void build(int pl, int pr, int p) {//线段树建树
		if(pl == pr) {
			addTag[p] = 0;
			tree[p] = array.get(pl);
			return;
		}
		int mid = (pl + pr) >> 1;
		build(pl, mid, p << 1);
		build(mid + 1, pr, p << 1 | 1);
		pushUp(p);
	}
	
	private void update(int pl, int pr, int p, int d) {//懒标记更新
		addTag[p] += d;
		tree[p] += d * (pr - pl + 1);
	}
	
	private void pushDown(int pl, int pr, int p) {//懒标记下传
		if(addTag[p] != 0) {
			int mid = (pl + pr) >> 1;
			update(pl, mid, p << 1, addTag[p]);
			update(mid + 1, pr, p << 1 | 1, addTag[p]);
			addTag[p] = 0;
		}
	}
	
	public void addModify(int L, int R, int pl, int pr, int p, int d) {//区间修改
		if(L <= pl && pr <= R) {
			update(pl, pr, p, d);
			return;
		}
		pushDown(pl, pr ,p);
		int mid = (pl + pr) >> 1;
		if(L <= mid) addModify(L, R, pl, mid, p << 1, d);
		if(R > mid) addModify(L, R, mid + 1, pr, p << 1 | 1, d);
		pushUp(p);
	}
	
	public int query(int L, int R, int pl, int pr, int p) {//区间查询
		if(L <= pl && pr <= R) {
			return tree[p];
		}
		pushDown(pl, pr, p);
		int res = 0, mid = (pl + pr) >> 1;
		if(L <= mid) res += query(L, R, pl, mid, p << 1);
		if(R > mid) res += query(L, R, mid + 1, pr, p << 1 | 1);
		return res;
	}
}
