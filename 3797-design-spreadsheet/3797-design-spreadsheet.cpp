class Spreadsheet {
private:
    vector<vector<int>> sheet;

    pair<int, int> getInd(string cell){
        if(cell[0] < 'A' || cell[0] > 'Z') return {-1, stoi(cell)};
        return {cell[0] - 'A', stoi(cell.substr(1))};
    }

public:
    Spreadsheet(int rows) {
        this->sheet = vector<vector<int>>(26, vector<int> (rows + 1, 0));
    }
    
    void setCell(string cell, int value) {
        auto [col, row] = getInd(cell);
        sheet[col][row] = value;
    }
    
    void resetCell(string cell) {
        auto [col, row] = getInd(cell);
        sheet[col][row] = 0;
    }
    
    int getValue(string formula) {
        int indPlus = 1;
        while(formula[indPlus] != '+') indPlus++;
        auto [col1, row1] = getInd(formula.substr(1, indPlus - 1));
        auto [col2, row2] = getInd(formula.substr(indPlus + 1));
        int ans = 0;
        if(col1 == -1) ans += row1;
        else ans += sheet[col1][row1];
        if(col2 == -1) ans += row2;
        else ans += sheet[col2][row2];
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */