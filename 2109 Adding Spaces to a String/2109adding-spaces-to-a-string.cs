public class Solution {
    public string AddSpaces(string s, int[] spaces) {
        StringBuilder sb = new StringBuilder();
        int j = 0;
        for(int i = 0; i<s.Length; i++){
            if(j<spaces.Length && spaces[j] == i){
                j++;
                sb.Append(" ");
            }
            sb.Append(s[i]);
        }
        return sb.ToString();
    }
}