class EvenThread extends Thread{
    public void run(){
     
        for (int i = 0; i <= 20; i++) {
              if(i % 2 == 0){
              try{
          Thread.sleep(500);
           }
        catch(InterruptedException e){}
                System.out.println(i);
                }
                
        }
     }
  }
class OddThread extends Thread{
    public void run(){
        
        for (int i = 0; i <= 20; i++) {
              if(i % 2 != 0){  try{
        Thread.sleep(500);
       }
      catch(InterruptedException e){}
                System.out.println(i);
                }
        }
     }
  }
  public class EvenOddThread{
  public static void main(String[] args){
        EvenThread e = new EvenThread();
        e.start();
        OddThread o = new OddThread();
        o.start();
  }
}
