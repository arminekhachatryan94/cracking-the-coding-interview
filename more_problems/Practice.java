import java.util.Arrays;
import java.util.HashMap;

class Practice {
    public static void main( String[] args ) {
        int D = 2;
        int[] A1 = { -1, 0, 1, 2, 3 };
        int[] A2 = {-1, 2, 4, 1, 0 };

        int[] S1 = solution(2, A1);
        int[] S2 = solution(3, A2);

        System.out.println(Arrays.toString(S1));
        System.out.println(Arrays.toString(S2));
    }

    /*
    Given an integer D and an array of integers A, find the
    Dth parent of every element in A
    */
    public static int[] solution(int D, int[] A){
        int[] ret = new int[A.length];
        HashMap<Integer, Integer> hash = new HashMap<>();

        for( int i = 0; i < A.length; i++ ){
            hash.put(A[i], i);
        }

        int parent = hash.get(-1);
        ret[parent] = -1;
        while( hash.get(parent) != null ){
            int temp = parent;
            parent = hash.get(parent);
            if( A[temp] == -1 ){
                ret[parent] = 1;
            }
            else {
                ret[parent] = ret[temp] + 1;
            }
            if( ret[temp] < D ){
                ret[temp] = -1;
            } else {
                ret[temp] -= D;
            }
        }
        if( ret[parent] < D ){
            ret[parent] = -1;
        } else {
            ret[parent] -= D;
        }

        return ret;
    }
}