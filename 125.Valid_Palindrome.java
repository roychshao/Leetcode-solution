class Solution {
  public boolean isPalindrome(String s) {
    String forward = "";
    String backward = "";
    for (int i = 0; i < s.length(); ++i) {
      if (Character.isLetter(s.charAt(i))) {
        forward += Character.toLowerCase(s.charAt(i));
      } else if (Character.isDigit(s.charAt(i))) {
        forward += s.charAt(i);
      }
    }
    for (int i = forward.length() - 1; i >= 0; --i) {
      backward += forward.charAt(i);
    }
    return forward.equals(backward);
  }
}
