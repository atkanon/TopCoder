import java.util.Set;
import java.util.HashSet;

public class PathGame {
	public String judge(String[] board) {
		int n = board[0].length();
		boolean[][] forbidden = new boolean[2][n];
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				if (board[i].charAt(j) == '#') {
						forbidden[i][j] = true;
						for (int y = j - 1; y <= j + 1; ++y)
							if (y >= 0 && y < n)
								forbidden[1 - i][y] = true;
				}
		int[][] grundy = new int[n + 1][16];
		for (int len = 1; len <= n; ++len)
			for (int mask = 0; mask < 16; ++mask) {
				Set<Integer> visited = new HashSet<>();
				for (int x = 0; x < 2; ++x)
					for (int y = 0; y < len; ++y) {
						if (y == 0 && (mask & 1 << x) != 0) continue;
						if (y == len - 1 && (mask & 1 << (2 + x)) != 0) continue;
						visited.add(grundy[y][(mask  & 3) | 1 << (3 - x)] ^ grundy[len - y - 1][(mask & 12) | 1 << (1 - x)]);						
					}
				while (visited.contains(grundy[len][mask]))
					++grundy[len][mask];
			}
		int answer = 0;
		for (int i = 0; i < n;)
			if (!forbidden[0][i] || !forbidden[1][i]) {
				int j = 1;
				while (j + 1 < n && (!forbidden[0][j + 1] || !forbidden[1][j + 1]))
					++j;
				int mask = 0;
				if (forbidden[0][i]) mask |= 1;
				if (forbidden[1][i]) mask |= 2;
				if (forbidden[0][j]) mask |= 4;
				if (forbidden[1][j]) mask |= 8;
				answer ^= grundy[j - i + 1][mask];
				i = j + 1;
			} else {
				++i;
			}
		return answer == 0 ? "Sothe" : "Snuke";
	}
}