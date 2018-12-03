import java.util.*;

  public class App{


    public static void main( String[] args ) {
      Scanner input = new Scanner( System.in );
      Probs p = new Probs();


      while ( input.hasNext() ) {
         String temp = input.nextLine();

          if ( temp.equals( "quit" ) ) System.exit(0);
          StringTokenizer st = new StringTokenizer(temp, " ");
          String pai = st.nextToken();

          //descarta os dois pontos
          st.nextToken();

        	 while(st.hasMoreTokens()){
              p.add(st.nextToken(),Integer.parseInt(st.nextToken())/100.0, pai);
          	}	  
        p.atualiza();
         //p.print();
         //System.out.println("----------------------------------------");
        }

     p.atualizaProbs();
     //p.print();
     //System.out.println("----------------------------------------");
     p.findMaiorProbs();
    } 
  }