import java.util.*;

class Main {
	public static void main(String[] args) {
		TaroJiroGrid obj = new TaroJiroGrid();

		{
			System.out.println("Case #0");
			String[] list = new String[]{"WB", "BB"};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 1);
		}
		{
			System.out.println("Case #1");
			String[] list = new String[]{"WB", "WW"};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 1);
		}
		{
			System.out.println("Case #2");
			String[] list = new String[]{"WB", "WW"};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 1);
		}
		{
			System.out.println("Case #3");
			String[] list = new String[]{"WB", "WB"};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 2);
		}
		{
			System.out.println("Case #4");
			String[] list = new String[]{"WBBW", "WBWB", "WWBB", "BWWW"};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 2);
		}
		{
			System.out.println("Case #5");
			String[] list = new String[]{
				"WBBWBB",
				"BBWBBW",
				"WWBWBW",
				"BWWBBB",
				"WBWBBW",
				"WWWBWB"
			};
			int res = obj.getNumber(list);
			System.out.println("res: " + res + ", ans: " + 1);
		}
	}
}

class TaroJiroGrid {

	private boolean check(String[] grid, int mask, char C) {
		int size = grid.length;
		for (int i = 0; i < size; i++) {
			char c = grid[0].charAt(i);
			if (mask == 0) c = C;
			int cnt = 1;
			for (int j = 1; j < size; j++) {
				char targetC = grid[j].charAt(i);
				if (mask == j) targetC = C;

				if (targetC == c) {
					cnt++;
				} else {
					c = targetC;
					cnt = 1;
				}
				if (cnt > size / 2) {
					return false;
				}
			}
		}
		return true;
	}
	public int getNumber(String[] grid) {
		int size = grid.length;

		if (this.check(grid, -1, 'X')) return 0;

		for (int i = 0; i < size; i++) {
			for (int c = 0; c < 2; c++) {
				if (this.check(grid, i, "WB".charAt(c))) {
					return 1;
				}
			}
		}

		return 2;
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
