import java.util.ArrayList;

/**
 * Test class
 * @author Reha Inan
 */
public class ArrayFunctions {
    /**
     * Remove Object to ArrayList
     * @param array Searcing ArrayList
     * @param index Arraylist Index
     * @param object Searching Object
     * @param <T> Package Branch Employee
     * @return ArrayList Index
     */
    public static <T> int removeObjectlist(ArrayList<T> array, int index,T object){

        int flag=1;
        for (int i = 0; i <index; i++) {
            if(object.equals(array.get(i))){
                array.remove(object);
                index--;
                flag=0;
                return index;
            }
        }
        if (1==flag){
            System.out.println("not here");
        }
        return index;
   }

    /**
     * Adding Object to ArrayList
     * @param arraylist Searching Arraylist
     * @param index
     * @param object
     * @param <E>
     * @return
     */
    public static <E> int  addObjecttolist (ArrayList<E> arraylist, int index, E object){

        boolean flag =true;

        if(object != null) {
            for (int i = 0; i <index; i++) {
                if(arraylist.contains(object)){
                    System.out.println("Already Member !!!!");
                    flag=false;
                    break;
                }
            }
        }else {
            System.out.println("Its empty(null)");
        }
        if (flag){
            arraylist.add(object);
            index++;
        }
    return index;
    }
    public static <E> E findObjectlist (ArrayList<E> arr ,int index,E findthis){
        if(arr.indexOf(findthis)==-1){
            System.out.println("Not found");
        }
        return arr.get(arr.indexOf(findthis));
    }
}
