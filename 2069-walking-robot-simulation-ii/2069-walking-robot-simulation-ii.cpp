class Robot {
private:
    int width, height, pos, perim;
    bool moved;

public:
    Robot(int width, int height) {
        this->height = height;
        this->width = width;
        this->pos = 0;
        this->moved = false;
        this->perim = 2*height + 2*width - 4;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % perim;
    }

   string getDir() {
        if (pos == 0) return moved ? "South" : "East";
        if (pos < width)             return "East";   
        if (pos < width + height - 1)    return "North";  
        if (pos < 2*width + height - 2)  return "West";   
        return "South";  
   }                                  

    vector<int> getPos() {
        if (pos < width)                  return {pos, 0};
        if (pos < width + height - 1)     return {width - 1, pos - width + 1};
        if (pos < 2*width + height - 2)   return {(width - 1) - (pos - (width - 1) - (height - 1)), height - 1}; // pos - (width - 1) - (height - 1)
        return {0, perim - pos};
    }
};

// (width - 1) - (pos - (width - 1) - (height - 1))

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */