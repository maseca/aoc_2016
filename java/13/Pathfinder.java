import java.math.BigInteger;
import java.util.*;

public class Pathfinder{
	public static void main(String[] args){
		final int INPUT = 1362;
		final int RANGE = 50;
		final int DESTX = 31;
		final int DESTY = 39;

		char[][] map = new char[RANGE][RANGE];

		for(int i = 0; i < RANGE; ++i)
			for(int j = 0; j < RANGE; ++j)
				if(isWall(j, i, INPUT))
					map[i][j] = '#';
				else
					map[i][j] = '.';
		
		/*
		for(int i = 0; i < RANGE; ++i)
			System.out.println(map[i]);
		*/

		System.out.println("Minimum Steps: " + minSteps(map,DESTX,DESTY,RANGE));

		/*
		for(int i = 0; i < RANGE; ++i)
			System.out.println(map[i]);
		*/
	}

	public static boolean isWall(int x, int y, int input){
		int count, strlen;
		BigInteger total = new BigInteger("0");
		String bin;
		
		count = 0;
		total = total.valueOf(x * x + 3 * x + 2 * x * y + y + y * y + input);
		bin = total.toString(2);
		strlen = bin.length();

		for(int i = 0; i < strlen; ++i)
			if(bin.charAt(i) == '1')
				++count;
		if(count % 2 == 0)
			return false;
		else
			return true;
	}


	public static void makeNeighbors(Deque<Node> unv, ArrayList<Node> vis, char[][] mz, int range){
		int pX = unv.getLast().posX;
		int pY = unv.getLast().posY;
		int d = unv.getLast().distance;
		boolean isDupe = false;
		int size = vis.size();

		for(int i = 0; i < size; ++i)
			if(pX == vis.get(i).posX && pY == vis.get(i).posY)
				isDupe = true;

		if(!isDupe){
			if(pY > 0 && mz[pY-1][pX] == '.')
				unv.push(new Node(pX,pY-1,d+1));
			if(pX > 0 && mz[pY][pX-1] == '.')
				unv.push(new Node(pX-1,pY,d+1));
			if(pY < range-1 && mz[pY+1][pX] == '.')
				unv.push(new Node(pX,pY+1,d+1));
			if(pX < range-1 && mz[pY][pX+1] == '.')
				unv.push(new Node(pX+1,pY,d+1));

			vis.add(new Node(pX, pY, d));
			mz[pY][pX] = 'O';
		}
		unv.removeLast();

	}

	public static int minSteps(char[][] maze, int destX, int destY, int ran){
		Deque<Node> unvisited = new ArrayDeque<Node>();
		ArrayList<Node> visited = new ArrayList<Node>();
		int vsize;

		unvisited.add(new Node(1,1,0));

		do{
			makeNeighbors(unvisited, visited, maze, ran);
			vsize = visited.size();
		}while(visited.get(vsize-1).posX != destX || visited.get(vsize-1).posY != destY);
		
		maze[destY][destX] = 'X';

		return visited.get(vsize-1).distance;
	}
}
