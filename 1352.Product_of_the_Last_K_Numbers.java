import java.util.ArrayList;
import java.util.List;

class ProductOfNumbers {

  private List<Integer> stream = null;
  private int product = 1;

  public ProductOfNumbers() {
    stream = new ArrayList<>();
  }

  public void add(int num) {
    if (num == 0) {
      stream = new ArrayList<>();
      product = 1;
      return;
    }
    product *= num;
    stream.add(product);
  }

  public int getProduct(int k) {
    if (stream.size() < k) return 0;
    int result = stream.get(stream.size() - 1);
    if (stream.size() == k) return result;
    return result / stream.get(stream.size() - 1 - k);
  }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such: ProductOfNumbers obj = new
 * ProductOfNumbers(); obj.add(num); int param_2 = obj.getProduct(k);
 */
