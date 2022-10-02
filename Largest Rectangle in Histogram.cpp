int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int cur = 0, maxArea = 0, top = 0;
        int *stack = new int[heights.size()]();
        stack[top] = -1;
        for(int i = 0; i < heights.size(); ++i){
            while(top>0 && heights[stack[top]] >= heights[i]){
                cur = (i-stack[top-1]-1)*heights[stack[top]];
                top--;
                maxArea = max(cur, maxArea);
            }
            stack[++top] = i;
        }
        delete [] stack;
        return maxArea;
    }
