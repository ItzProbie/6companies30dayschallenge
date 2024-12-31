//Sol - 1
class Solution {

    //if they overlap then atleast a single point on the sides of the rectangle must overlap 

    void buildSides(int x1 , int y1 , int x2 , int y2 , vector<tuple<int,int,int>>& sides){

        //x3y3       x2y2
        //x1y1       x4y4

        int x3 , y3 , x4 , y4;
        x3 = x1 , y3 = y2;
        x4 = x2 , y4 = y1;

        sides.push_back(make_tuple(x1 , x4 , y1));
        sides.push_back(make_tuple(x3 , x2 , y2));
        sides.push_back(make_tuple(y1 , y3 , x1));
        sides.push_back(make_tuple(y4 , y2 , x2));
        

    }

    bool inCircle(int xc , int yc , int rad , int x , int y){

        return rad*rad >= ((x - xc) * (x - xc) + (y - yc) * (y - yc));

    }

public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        vector<tuple<int,int,int>>sides;
        buildSides(x1 , y1 , x2 , y2 , sides);

        int X1 = get<0>(sides[0]);
        int X4 = get<1>(sides[0]);
        int Y1 = get<0>(sides[2]);
        int Y3 = get<1>(sides[2]);

        //completely overlapped circle
        if(xCenter >= X1 && xCenter <= X4 && yCenter >= Y1 && yCenter <= Y3)
            return true;

        for(int i = 0 ; i < 2 ; i++){
            auto [start , end , y] = sides[i];

            while(start <= end){
                if(inCircle(xCenter , yCenter , radius , start , y))
                    return true;
                start++;
            }

        }
        for(int i = 2 ; i < 4 ; i++){
            auto [start , end , x] = sides[i];

            while(start <= end){
                if(inCircle(xCenter , yCenter , radius , x , start))
                    return true;
                start++;
            }

        }

        return false;

    }
};

//Sol - 2
class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        
        int nx = max(min(x2 , xc) , x1);
        int ny = max(min(y2 , yc) , y1);
        return pow(nx - xc , 2) + pow(ny - yc , 2) <= pow(radius , 2);

    }
};