class BrowserHistory {
public:
    stack<string> undo;
    stack<string> redo;

    BrowserHistory(string homepage) {
        undo.push(homepage);
    }
    
    void visit(string url) {
        redo = stack<string>();
        undo.push(url);
    }
    
    string back(int steps) {
        for(int i = 0; i<steps; i++){
            if(undo.size() == 1) break;
            redo.push(undo.top());
            undo.pop();
        }
        return undo.top();
    }
    
    string forward(int steps) {
        for(int i = 0; i<steps; i++){
            if(redo.empty()) break;
            undo.push(redo.top());
            redo.pop();
        }
        return undo.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */