#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node {
	public:
		string charNode_;
		int count_;
		string binCode_;
		Node* leftPtr_;
		Node* rightPtr_;
		////
		Node (int value) : count_(value){
			leftPtr_ = nullptr;
			rightPtr_ = nullptr;
			charNode_ += ""; 
				
		} 
		Node (char charNode, int count){
		charNode_ = charNode;
		count_ = count;
		leftPtr_ = nullptr;
		rightPtr_ = nullptr;
		}
		void insertingValues (vector<Node*>& vec, string text){
			for(int i = 0; i < text.length(); i++){
				int count = 1;
				for(int j = i + 1; j <text.length();j++){
					if (text[i] == text[j]){
						count = count + 1;
					}
				}
				Node* node = new Node(text[i],count);
				vec.push_back(node);
			}

		}
		void deletingRep (vector<Node*>& vec){
			for (int i = 0; i <vec.size(); i++){
				for(int j = i + 1; j < vec.size(); j++){
					if(vec[i] -> charNode_ == vec[j]->charNode_){
						vec.erase(vec.begin() + j);
					}
				}
				
			}
		}
	void orderingValues(vector<Node*>& vec){
		for(int i =1; i < vec.size(); i++){
			Node* key = nullptr;
			key = vec[i];
			int j = i -1;
			while(j > - 1 and vec[j] -> count_ > key -> count_){
				vec[j + 1] = vec[j];
				j = j -1;
			}
		vec[j + 1] = key;
		}	
	}
	Node* insertingNode (Node* returnNode, Node* nNode){
		if(returnNode == nullptr){
			return nNode;
		}
		if(returnNode->count_ == nNode->count_){
			Node* sNode =  new Node(nNode->count_ * 2);
			sNode -> leftPtr_ = returnNode;
			sNode -> rightPtr_ = nNode;
			return sNode;
		}else if (returnNode->count_ > nNode -> count_){
			returnNode -> count_ = returnNode->count_ + nNode->count_;
			returnNode -> leftPtr_ = insertingNode(returnNode->leftPtr_,nNode);
		}else{
			returnNode->count_ = returnNode->count_ + nNode->count_;
			returnNode->rightPtr_=insertingNode(returnNode->rightPtr_,nNode);	
		}
		return returnNode;
	}
	Node*  buildingTree (vector <Node*>& vec){
		for(int i = 0; i < vec.size() - 1; i++){
			 Node* sNode = new Node(vec[i]->count_ + vec[i +1]->count_);
			if(vec[i]-> count_ > vec[i + 1] -> count_){
				sNode->rightPtr_= vec[i];
				sNode->leftPtr_=vec[i+1];
			}else{
				sNode->rightPtr_= vec[i+1];
				sNode->leftPtr_=vec[i];
			}
			vec[i + 1] = sNode;
			orderingValues (ref(vec));
		}
		return vec[vec.size() -1];	
	}
	void insertBinCode (Node* root, string myBin){
		if (root -> leftPtr_ !=nullptr){
			insertBinCode (root->leftPtr_, myBin+="1");
			myBin.pop_back();
		}
		if (root -> rightPtr_ != nullptr){
			insertBinCode (root->rightPtr_,myBin+="0");
			myBin.pop_back();
		}
		root -> binCode_ = myBin;

	}
      void printingValues(Node* root){
	       if (root -> leftPtr_ != nullptr){
	                printingValues (root -> leftPtr_);				
	       }
	       if (root ->charNode_ !=""){
		 	cout << root -> charNode_ <<" "<<root -> binCode_ <<endl;
	       }if(root -> rightPtr_ != nullptr){
			printingValues (root -> rightPtr_);
	       }
      }
	void destroyTree(Node * root){
		if(root -> leftPtr_ != nullptr){
			destroyTree (root -> leftPtr_);
		}
		if(root -> rightPtr_ != nullptr){
			destroyTree (root -> rightPtr_);
		}
		delete root;
 	}
		};

int main (int argc, char* argv[]){
	if(argc == 1){
		cout << "You didn't put any value"<< endl;
		return 0;
	}else if (argc >2) { 
		cout << "Too many values..." << endl;
		return 0;
	}	
	string text = argv[1];
	Node* root = nullptr;
	vector<Node*> vec;
	root -> insertingValues(ref(vec), text);
	root -> deletingRep(ref(vec));
	root -> orderingValues(ref(vec));
	root = root->buildingTree(ref(vec));
	root -> insertBinCode(root,"");
	root -> printingValues(root);
	root -> destroyTree(root);
	return 0;
}




