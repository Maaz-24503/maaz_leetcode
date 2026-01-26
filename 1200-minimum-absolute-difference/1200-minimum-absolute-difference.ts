function minimumAbsDifference(arr: number[]): number[][] {
    const sorted: number[] = arr.sort((a, b) => { return a > b ? 1 : -1; });
    var mini: number = Number.MAX_SAFE_INTEGER;
    for (var i = 0; i < sorted.length - 1; i++)
        mini = Math.min(sorted[i + 1] - sorted[i], mini);
    const ans: number[][] = new Array();
    for (var i = 0; i < sorted.length - 1; i++)
        if (sorted[i + 1] - sorted[i] === mini)
            ans.push([sorted[i], sorted[i + 1]]);
    return ans;
};