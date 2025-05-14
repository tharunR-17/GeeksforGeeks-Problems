class Solution {

    // Main function to generate the nth term of the Count and Say sequence
    public String countAndSay(int n) {
        // Base case: the first term is always "1"
        if (n == 1) {
            return "1";
        }

        // Initialize the sequence starting from the first term
        String prev = "1";

        // Generate terms from the 2nd to the nth
        for (int i = 2; i <= n; i++) {
            StringBuilder next = new StringBuilder(); // To build the next term
            int count = 1; // Counter for consecutive characters

            // Iterate over the previous term starting from the second character
            for (int j = 1; j < prev.length(); j++) {
                // If current character is same as previous, increment count
                if (prev.charAt(j) == prev.charAt(j - 1)) {
                    count++;
                } else {
                    // Append count and character to next term
                    next.append(count).append(prev.charAt(j - 1));
                    count = 1; // Reset count for the new character
                }
            }

            // Append the last group (since it won't be handled in the loop)
            next.append(count).append(prev.charAt(prev.length() - 1));

            // Update prev to be the next term for the next iteration
            prev = next.toString();
        }

        // Return the nth term
        return prev;
    }
}
