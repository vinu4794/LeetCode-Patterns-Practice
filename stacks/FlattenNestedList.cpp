class NestedIterator
{
    std::stack<NestedDirectory *> stackDS;

    public:
        NestedIterator(vector<NestedDirectory *> nestedList)
        {
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stackDS.push(nestedList[i]);
            }
        }

        bool HasNext()
        {
            if (!stackDS.empty()) {
                NestedDirectory *currentObj = stackDS.top();

                // if it is a list
                if (!currentObj->isFile()) {
                    //Flatten it 
                    stackDS.pop();
                    
                    vector<NestedDirectory *> list = currentObj->getList();
                    for (int i = list.size() - 1; i >= 0 ; i--) {
                        stackDS.push(list[i]);
                    }                    
                }
                return true;              
                
            }
            else {
                return false;
            }
        }

        int Next()
        {
            if (HasNext())
            {
                auto top = this->stackDS.top();
                this->stackDS.pop();
                return top->getFile();
            }

            return -1;
        }
};
