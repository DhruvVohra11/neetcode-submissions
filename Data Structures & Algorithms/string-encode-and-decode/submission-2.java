class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String x : strs) {
            sb.append(x).append(",##,");  // keep your delimiter approach
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        // Keep trailing empty strings
        String[] arr = str.split(",##,", -1);

        // Because encode always adds a trailing comma, split will produce
        // an extra "" at the end. Remove it.
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