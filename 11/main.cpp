#include <deque>
#include <vector>
#include <iostream>

using namespace std;

struct Node{
	unsigned thuGen: 2; unsigned thuChip: 2;
	unsigned pluGen: 2; unsigned pluChip: 2;
	unsigned strGen: 2; unsigned strChip: 2;
	unsigned proGen: 2; unsigned proChip: 2;
	unsigned rutGen: 2; unsigned rutChip: 2;
	unsigned elevator: 2; unsigned tentDist: 10;
};

Node* createNode(unsigned thuG, unsigned thuC, 
				 unsigned pluG, unsigned pluC, 
				 unsigned strG, unsigned strC, 
				 unsigned proG, unsigned proC, 
				 unsigned rutG, unsigned rutC, 
				 unsigned elev, unsigned tDist){
	Node* ret = new Node();
	
	ret->thuGen = thuG; ret->thuChip = thuC;
	ret->pluGen = pluG; ret->pluChip = pluC;
	ret->strGen = strG; ret->strChip = strC;
	ret->proGen = proG; ret->proChip = proC;
	ret->rutGen = rutG; ret->rutChip = rutC;
	ret->elevator = elev; ret->tentDist = tDist;

	return ret;
}

Node* getNeighbor(Node* seed, vector<Node*>& visit, vector<Node*>::size_type sz, bool& success){
	bool isUnique;
	unsigned short counter = 0;
	Node* ret = new Node();

	ret->tentDist = seed->tentDist;

	do{
		//logic goes here...
		for(unsigned i=0; i<sz; ++i)
			if(*ret == visit[i]){
				isUnique = false;
				++counter;
			}
	}while(!isUnique);

	return ret;
}

int main(){
	deque<Node*> unvisited;
	vector<Node*> visited;
	vector<Node*>::size_type sizeV;
	bool madeNeighbor, isDupe;

	unvisited.push_back(createNode(0,0,0,1,0,1,2,2,2,2,0,0));

	do{
		sizeV = visited.size();
		do{
			madeNeighbor = true;
			isDupe = false;
			
			for(deque<Node*>::iterator it=unvisited.begin(); it!=unvisited.end(); ++it)
				if(*it == deque.back() && &(*it) != &deque.back()){
					deque.pop_back();
					isDupe = true;
					break;
				}
			if(!isDupe){
				madeNeighbor = false;
				unvisited.push_front(getNeighbor(unvisited.back(), visited, sizeV, madeNeighbors));
				if(!madeNeighbor)
					unvisited.pop_front();
			}
		}while(madeNeighbor);

		visited.push_back(unvisited.back());
		delete unvisited.back();
		unvisited.pop_back();
	}while(visited.back().thuGen != 3 && visited.back().thuChip != 3 &&
		   visited.back().pluGen != 3 && visited.back().pluChip != 3 &&
		   visited.back().strGen != 3 && visited.back().strChip != 3 &&
		   visited.back().proGen != 3 && visited.back().proChip != 3 &&
		   visited.back().rutGen != 3 && visited.back().rutChip != 3 &&
		   visited.back().elevator != 3);

	cout << visited.back().tentDist << endl;
	return 0;
}
