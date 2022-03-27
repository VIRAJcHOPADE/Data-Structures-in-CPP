/*Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum
 element present. Remove and return the minimum element.
 */

using namespace std;
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		
        int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();
        
        int parentind=0;
        int leftind=2*parentind+1;
        int rightind=2*parentind+2;
        
        while(leftind<pq.size()){
            int midind=parentind;
            if(pq[midind]>pq[leftind]){
                midind=leftind;
            }
            
            if(pq[midind]>pq[rightind] && rightind<pq.size()){
                midind=rightind;
            }
//             if(pq[parentind]>pq[leftind]){
//                 midind=leftind;
//             }
            
//             if(pq[parentind]>pq[rightind] && pq[rightind]<pq.size()){
//                 midind=rightind;
//             }
            
            if(midind==parentind){
                break;
            }
            
            int temp = pq[midind];
			pq[midind] = pq[parentind];
			pq[parentind] = temp;
            
            parentind=midind;
              leftind=2*parentind+1;
              rightind=2*parentind+2;
            
        }
        return ans;
    }
};