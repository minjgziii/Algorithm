import java.util.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
//         Deque<Integer> dq = new ArrayDeque<>();
//         Stack<Integer> st = new Stack<>();
//         Stack<Integer> buger = new Stack<>();
        
        
//         for(int i=0; i<ingredient.length; i++) {
//             if(buger.isEmpty() &&ingredient[i] == 1) {
//                 buger.push(ingredient[i]);
//             }
//             else if(!buger.isEmpty()){
//                 if(buger.peek() == 1 && ingredient[i] == 1) {
//                 buger.push(ingredient[i]);
//                 }
//                 if(buger.peek() == 1 && ingredient[i] == 2) {
//                     buger.push(ingredient[i]);
//                 }
//                 if(buger.peek() == 2 && ingredient[i] == 3) {
//                     buger.push(ingredient[i]);
//                 }
//                 if(buger.peek() == 3 && ingredient[i] == 1) {
//                     buger.push(ingredient[i]);
//                     answer++;
//                     for(int j=0; j<4; j++) {
//                         buger.pop();
//                     }
//                 }
//             }
//             System.out.println(buger);
            
//         }
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<ingredient.length; i++) {
            if(ingredient[i]==1 && st.search(3)==1 && st.search(2)==2 && st.search(1)==3){
                st.pop();
                st.pop();
                st.pop();
                answer++;
            }
            else{
                st.push(ingredient[i]);
            }
        }
        return answer;
    }
}