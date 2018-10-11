import java.util.*;


public class Main{

    public static class Node{
        public boolean flag = false;
        public ArrayList<Node> hasa = new ArrayList<>();
        public ArrayList<Node> isa = new ArrayList<>();
        public String nome;

        public Node(String nome) {
            this.nome = nome;
        }
    }

    public static boolean findIs(Node inicio, Node fim){
        if (inicio == fim) return true;

        if (inicio.flag){
            return inicio.flag = false;

        }
        inicio.flag = true;

        boolean resp = false;
        for (Node n: inicio.isa){
            if (resp = findIs(n, fim)) break;
        }

        inicio.flag = false;
        return resp;
    }

    public static boolean findAll(Node inicio, Node fim, boolean usei_has){
        if (inicio == fim ) return usei_has;
        if (inicio.flag) return inicio.flag = false;

        inicio.flag = true;

        boolean resp = false;

        for (Node n: inicio.isa){
            resp = resp || findAll(n, fim, usei_has);
        }

        for (Node n: inicio.hasa){
            resp = resp || findAll(n, fim, true);
        }

        inicio.flag = false;
        return resp;

    }


    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            HashMap<String, Node> grafinho = new HashMap<>();
            int relations, queries;
            relations = in.nextInt();
            queries = in.nextInt();

            while(relations -- > 0){
                String classe1 = in.next();
                String relacao = in.next();
                String classe2 = in.next();

                if (!grafinho.containsKey(classe1)) grafinho.put(classe1, new Node(classe1));
                if (!grafinho.containsKey(classe2)) grafinho.put(classe2, new Node(classe2));

                Node n1 = grafinho.get(classe1);
                Node n2 = grafinho.get(classe2);

                if (relacao.equals("has-a")) n1.hasa.add(n2);
                                        else n1.isa.add(n2);
            }

            for(int i = 1; i <= queries; i ++){
                String classe1 = in.next();
                String relacao = in.next();
                String classe2 = in.next();

                if (!grafinho.containsKey(classe1)) grafinho.put(classe1, new Node(classe1));
                if (!grafinho.containsKey(classe2)) grafinho.put(classe2, new Node(classe2));

                Node n1 = grafinho.get(classe1);
                Node n2 = grafinho.get(classe2);

                boolean controle = false;

                if( relacao.equals("is-a") ) controle = findIs(n1, n2);
                else {
                    if(classe1.equals(classe2)) controle = true;
                    else controle = findAll(n1, n2, false);
                }

                System.out.println("Query " + i + ": " + controle);

            }
        }
    }
}
