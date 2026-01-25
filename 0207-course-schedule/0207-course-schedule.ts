function canFinish(numCourses: number, prerequisites: number[][]): boolean {
    const adjList : number[][] = new Array(numCourses);
    const inDegree : number[] = new Array(numCourses).fill(0);

    for(var i = 0; i < numCourses; i++) adjList[i] = new Array();

    for(const [a, b] of prerequisites){
        adjList[b].push(a);
        inDegree[a]++;
    }

    const st : number[] = []

    for(var i = 0; i < numCourses; i++){
        if(inDegree[i] == 0) st.push(i);
    }

    var done : number = 0;

    while(st.length > 0){
        const u : number = st.pop();
        done++;
        for(const v of adjList[u]){
            inDegree[v]--;
            if(inDegree[v] == 0) st.push(v);
        }
    }

    return done === numCourses;
};