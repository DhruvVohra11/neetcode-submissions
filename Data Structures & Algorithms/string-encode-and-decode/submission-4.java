class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String x : strs) {
            sb.append(x).append(",##,");  
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        String[] arr = str.split(",##,", -1);
        int n = arr.length;
        if (n > 0 && arr[n - 1].equals("")) {
            n--;
        }
        List<String> list = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            list.add(arr[i]);
        }
        return list;
}
};