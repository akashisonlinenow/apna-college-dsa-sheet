class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder result = new StringBuilder();
        Arrays.sort(strs);

        char first[] = strs[0].toCharArray();
        char second[] = strs[strs.length-1].toCharArray();

        for(int i=0;i<first.length;i++){
            if(first[i]!=second[i])
                break;
            result.append(first[i]);
        }
        return result.toString();
    }
}