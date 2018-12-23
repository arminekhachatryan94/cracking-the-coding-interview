import java.util.Arrays;
import java.util.HashMap;

class Practice {
    public static void main( String[] args ) {
        // parentD
        int[] A1 = { -1, 0, 1, 2, 3 };
        System.out.println(Arrays.toString(parentD(2, A1)));

        int[] A2 = {-1, 2, 4, 1, 0 };
        System.out.println(Arrays.toString(parentD(3, A2)));

        // housesAndStores
        int[] houses1 = { 1, 5, 20, 11, 16 };
        int[] stores1 = { 5, 10, 17 };
        System.out.println(Arrays.toString(housesAndStores(houses1, stores1)));

        // numJewelsInStones
        String J1 = "aA", S1 = "aAAbbbb";
        System.out.println("Jewels: " + J1 + ", Stones: " + S1 + ", count: " + numJewelsInStones(J1, S1));

        String J2 = "z", S2 = "ZZ";
        System.out.println("Jewels: " + J2 + ", Stones: " + S2 + ", count: " + numJewelsInStones(J2, S2));

        // lastRequest
        int[] capacity = {5, 1, 2};
        System.out.println("lastRequest: " + lastRequest(capacity, 2));

        // addTwoLists(new ListNode(1), new ListNode(2));
        
    }

    /*
    Given an integer D and an array of integers A, find the
    Dth parent of every element in A
    */
    public static int[] parentD(int D, int[] A){
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

    /*
    Given an array of houses and an array of stores,
    find the closest store to every house.
    */
    public static int[] housesAndStores(int[] houses, int[] stores) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        for( int i = 0; i < houses.length; i++ ){
            hash.put(houses[i], i);
        }

        // sort arrays
        java.util.Arrays.sort(houses);
        java.util.Arrays.sort(stores);

        int[] closest = new int[houses.length];
        int i = 0, j = 0;
        System.out.println("here");

        while( i < houses.length && j < stores.length ){
            System.out.println(houses[i] + " " + stores[j]);

            if( houses[i] == stores[j] ){
                closest[hash.get(houses[i])] = stores[j];
                i++;
            } else if( houses[i] > stores[j] ){
                j++;
            } else if( houses[i] < stores[j] ){
                if( j != 0 ){
                    if( Math.abs(houses[i] - stores[j]) < Math.abs(houses[i] - stores[j-1]) ){
                        closest[hash.get(houses[i])] = stores[j];
                    } else {
                        closest[hash.get(houses[i])] = stores[j-1];
                    }
                } else {
                    closest[hash.get(houses[i])] = stores[j];
                }
                i++;
            }
        }
        for( ; i < houses.length; i++ ){
            closest[hash.get(houses[i])] = stores[stores.length-1];
        }
        return closest;
    }

    /*
    Given two strings, J and S:
    J represents the type of stones that are jewels,
    and S represents the stones you have
    Find the number of stones you have that are jewels.
    */
    public static int numJewelsInStones(String J, String S) {
        HashMap<Character, Integer> jewels = new HashMap<>();
        for( int jewel = 0; jewel < J.length(); jewel++ ){
            jewels.put(J.charAt(jewel), jewel);
        }

        int count = 0;
        for( int stone = 0; stone < S.length(); stone++ ){
            if( jewels.get(S.charAt(stone)) != null ){
                count++;
            }
        }
        
        return count;
    }

    /*
    Given array S (capacities for servers) and a server (i),
    find the request which fills server i.
    */
    public static int lastRequest(int[] capacity, int server){
        int server_capacity = capacity[server];
        int total = 0;
        for( int i = 0; i < capacity.length; i++ ){
            if( i <= server_capacity ){
                if( capacity[i] > server_capacity ){
                    total += server_capacity;
                } else {
                    total += capacity[i];
                }
            } else {
                if( capacity[i] == 0 ){
                    ;
                } else if( capacity[i] > server_capacity ){
                    total += server_capacity-1;
                } else {
                    total += capacity[i]-1;
                }
            }
        }
        return total;
    }

    /*
    There is a robot starting at position (0, 0), the origin, on a 2D plane.
    Given a sequence of its moves, judge if this robot ends up at (0, 0) after
    it completes its moves.
    The move sequence is represented by a string, and the character moves[i]
    represents its ith move. Valid moves are R (right), L (left), U (up), and
    D (down). If the robot returns to the origin after it finishes all of its
    moves, return true. Otherwise, return false.
    */
    public boolean judgeCircle(String moves) {
        /*
        0 => U/D
        1 => L/R
        */
        int[] m = new int[4];
        for( int i = 0; i < moves.length(); i++ ){
            if( moves.charAt(i) == 'U'){
                m[0]++;
            } else if( moves.charAt(i) == 'D' ){
                m[0]--;
            } else if( moves.charAt(i) == 'R' ){
                m[1]++;
            } else if( moves.charAt(i) == 'L' ){
                m[1]--;
            }
        }
        return (m[0] == 0 && m[1] == 0 ? true : false);
    }
/*
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode addTwoLists(ListNode l1, ListNode l2) {
        int _l1 = 0;
        while( l1 != null ){
            _l1 *= 10;
            _l1 += l1.val;
            l1 = l1.next;
        }
        
        int _l2 = 0;
        while( l2 != null ){
            _l2 *= 10;
            _l2 += l2.val;
            l2 = l2.next;
        }
        
        String _l3 = Integer.toString(_l1 + _l2);
        
        ListNode temp = new ListNode(_l3.charAt(_l3.length()-1));
        
        ListNode l3 = temp;
        for( char c: new StringBuilder(_l3).reverse().toString().toCharArray() ){
            if( c == _l3.charAt(0) ){
                ;
            } else {
                ListNode t = temp;
                temp = new ListNode(c);
                temp.next = t;
            }
        }
        
        System.out.println(l3.val);
        return l3;
    }
    */
}