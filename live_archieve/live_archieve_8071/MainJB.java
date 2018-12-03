import java.util.*;

public class MainJB {

  public static class Node {
    public boolean flag = false;
    public boolean ready = false;
    public boolean answer = false;
    public ArrayList<Node> hasa = new ArrayList<>();
    public ArrayList<Node> isa = new ArrayList<>();
    public String nome;

    public Node( String nome ) {
      this.nome = nome;
    }
  }

  public static void main( String args[] ) {
    Scanner in = new Scanner( System.in );
    while( in.hasNext() ) {

      // Leitura das relacoes, continua como sempre foi
      HashMap<String, Node> grafinho = new HashMap<>();
      int relations, queries;
      relations = in.nextInt();
      queries = in.nextInt();

      // Ler as relacoes
      for( int i = 1; i <= relations; i ++ ) {
        String classe1 = in.next();
        String relacao = in.next();
        String classe2 = in.next();

        if ( !grafinho.containsKey( classe1 ) ) grafinho.put( classe1, new Node( classe1 ) );
        if ( !grafinho.containsKey( classe2 ) ) grafinho.put( classe2, new Node( classe2 ) );

        Node n1 = grafinho.get( classe1 );
        Node n2 = grafinho.get( classe2 );

        if ( relacao.equals( "has-a" ) ) n1.hasa.add( n2 );
        else n1.isa.add( n2 );
      }

      // Fazer o fechamento transitivo das relações (uma vez só!!)
      // Podiam ser 4 grupos de laços, juntei em dois pra economizar
      // uns trocos.


      //enquanto puder ligar alguma coisa faça:
      while(true){
        boolean continua = false;

        // A is-a B is-a C  => A is-a C
        // A is-a B has-a C => A has-a C
        // para todo nodo A:
        //   para todo nodo B em A.isa:
        //     para todo nodo C em B.isa:
        //       se A ainda nao ligar com C
        //         faz A is-a C
        //     para todo nodo C em B.hasa:
        //       se A ainda nao ligar com C
        //         faz A has-a C

        for(Node a: grafinho.values()){
            ArrayList <Node> new_hasa = new ArrayList<Node>();
            ArrayList <Node> new_isa = new ArrayList<Node>();
            for(Node b : a.isa){
                for(Node c : b.isa){
                    if(!a.isa.contains(c)){
                        new_isa.add(c);
                        continua = true;
                    }
                }
                for (Node c : b.hasa){
                    if(!a.hasa.contains(c)){
                        new_hasa.add(c);
                        continua = true;
                    }
                }
            }
            a.hasa.addAll(new_hasa);
            a.isa.addAll(new_isa);
        }


        // A has-a B has-a C => A has-a C
        // A has-a B is-a C  => A has-a C
        // para todo nodo A:
        //   para todo nodo B em A.hasa:
        //     para todo nodo C em B.hasa:
        //       se A ainda nao ligar com C
        //         faz A has-a C
        //     para todo nodo C em B.isa:
        //       se A ainda nao ligar com C
        //         faz A has-a C


        for(Node a: grafinho.values()){
            ArrayList <Node> new_hasa = new ArrayList<Node>();
            ArrayList <Node> new_isa = new ArrayList<Node>();
            for(Node b : a.hasa){
                for(Node c : b.hasa){
                    if(!a.hasa.contains(c)){
                        new_hasa.add(c);
                        continua = true;
                    }
                }
                for (Node c : b.isa){
                    if(!a.hasa.contains(c)){
                        new_hasa.add(c);
                        continua = true;
                    }
                }
            }
            a.hasa.addAll(new_hasa);
            a.isa.addAll(new_isa);
        }

        if(!continua) break;

      }
      for( int i = 1; i <= queries; i ++ ) {
        String classe1 = in.next();
        String relacao = in.next();
        String classe2 = in.next();

        //só vai na relação adequada da classe1 e verifica se classe2 tá lá...
        Node n1 = grafinho.get(classe1);
        Node n2 = grafinho.get(classe2);

        boolean controle = false;
        if(relacao.equals("is-a")){
            if(classe1.equals(classe2)) controle = true;
            else controle = n1.isa.contains(n2);

        }
        else controle = n1.hasa.contains(n2);
        System.out.println("Query " + i + ": " + controle);


      }
    }
  }
}
