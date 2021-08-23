class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        return (D - B) * (C - A) - max(0, (min(C, G) - max(A, E))) * max(0, (min(D, H) - max(B, F))) + (G - E) * (H - F) ;
    }
};
