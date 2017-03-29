#include <vector>
#include <deque>
#include <bitset>
#include <stdio.h>
#include <string>
using namespace std;

const int INPUT = 1362;
const unsigned char RANGE = 50;
const unsigned char DESTX = 31;
const unsigned char DESTY = 39;

struct Node{
	unsigned char posX;
	unsigned char posY;
	unsigned short distance;
	Node(unsigned char x, unsigned char y, unsigned short dist);
};

Node::Node(unsigned char x, unsigned char y, unsigned short dist){
	posX = x;
	posY = y;
	distance = dist;
}

bool isWall(int posX, int posY, int input){
	int total, count;
	string bin;
	
	count = 0;
	total = posX * posX + 3 * posX + 2 * posX * posY + posY + posY * posY + input;
	bin = bitset<256>(total).to_string();

	for(int i = 0; i < 256; ++i)
		if(bin.at(i) == '1')
			++count;
	if(count % 2 == 0)
		return false;
	else
		return true;
}

void makeNeighbors(deque<Node*>& unv, vector<Node*>& vis, char mz[RANGE][RANGE+1]){
	unsigned char pX = unv.back()->posX;
	unsigned char pY = unv.back()->posY;
	unsigned short d = unv.back()->distance;
	bool isDupe = false;
	vector<Node*>::size_type size = vis.size();

	for(unsigned i = 0; i < size; ++i)
		if(pX == vis[i]->posX && pY == vis[i]->posY)
			isDupe = true;

	if(!isDupe){
		if(pY > 0 && mz[pY-1][pX] == '.')
			unv.push_front(new Node(pX,pY-1,d+1));
		if(pX > 0 && mz[pY][pX-1] == '.')
			unv.push_front(new Node(pX-1,pY,d+1));
		if(pY < RANGE-1 && mz[pY+1][pX] == '.')
			unv.push_front(new Node(pX,pY+1,d+1));
		if(pX < RANGE-1 && mz[pY][pX+1] == '.')
			unv.push_front(new Node(pX+1,pY,d+1));

		vis.push_back(new Node(pX, pY, d));
		mz[pY][pX] = 'O';
	}

	unv.pop_back();
}

unsigned short minSteps(char maze[RANGE][RANGE+1], unsigned char destX, unsigned char destY){
	deque<Node*> unvisited;
	vector<Node*> visited;

	unvisited.push_back(new Node(1,1,0));

	do{
		makeNeighbors(unvisited, visited, maze);
	}while(visited.back()->posX != destX || visited.back()->posY != destY);
	
	maze[destY][destX] = 'X';

	return visited.back()->distance;
}

int main(){
	char map[RANGE][RANGE+1];

	for(unsigned char i = 0; i < RANGE; ++i)
		for(unsigned char j = 0; j < RANGE; ++j)
			if(isWall(j, i, INPUT))
				map[i][j] = '#';
			else
				map[i][j] = '.';

	printf("Minimum Steps: %u\n", minSteps(map,DESTX,DESTY));

	for(unsigned char i = 0; i < RANGE; ++i){
		map[i][RANGE] = '\0';
		//puts(map[i]);
	}

	return 0;
}
