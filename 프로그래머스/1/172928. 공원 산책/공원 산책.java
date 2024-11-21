import java.util.*;

class Solution {
    public int[] solution(String[] park, String[] routes) {
        int x = 0;
        int y = 0;
        
        for(int i=0; i<park.length; i++){
            for(int j=0; j<park[i].length(); j++){
                if(park[i].charAt(j)=='S'){
                    x=j;
                    y=i;
                }
            }
        }
        
        for(String route : routes){
            String[] routeSplit = route.split(" ");
            int sss =Integer.parseInt(routeSplit[1]);
            if(routeSplit[0].equals("N")){
                if(y-sss>=0){
                    for(int i=1; i<=sss; i++){
                        if(park[y-i].charAt(x)=='X'){
                            break;
                        }
                        if(i==sss){
                            y=y-i;
                        }
                    }
                }
            }
            else if(routeSplit[0].equals("S")){
                if(y+sss<park.length){
                    for(int i=1; i<=sss; i++){
                        if(park[y+i].charAt(x)=='X'){
                            break;
                        }
                        if(i==sss){
                            y=y+i;
                        }
                    }
                }
            }
            else if(routeSplit[0].equals("E")){
                if(x+sss<park[0].length()){
                    for(int i=1; i<=sss; i++){
                        if(park[y].charAt(x+i)=='X'){
                            break;
                        }
                        if(i==sss){
                            x=x+i;
                        }
                    }
                }
            }
            else if(routeSplit[0].equals("W")){
                if(x-sss>=0){
                    for(int i=1; i<=sss; i++){
                        if(park[y].charAt(x-i)=='X'){
                            break;
                        }
                        if(i==sss){
                            x=x-i;
                        }
                    }
                }
            }
        }
        return new int[]{y,x};
    }
}