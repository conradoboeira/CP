import java.util.*;

public class Megaprojeto{

    private static class Node{
        String nome;
        int custo;
        List<Aresta> arestas;

        private Node(String nome, int custo){
            this.nome = nome;
            this.custo = custo;
            arestas = new LinkedList<Aresta>();
        }

    }

    private static class Aresta{
        String destino;
        int custo;


        private Aresta(String destino, int custo){
            this.destino = destino;
            this.custo = custo;
        }

    }
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        int num_nodos = Integer.parseInt(input.nextLine());

        Map <String, Node> projetos = new HashMap <String, Node>();

        for(int i = 0; i < num_nodos; i ++){

            String temp = input.nextLine();
            StringTokenizer st = new StringTokenizer(temp, " ");

            String nome = st.nextToken();
            Node new_node = new Node(nome, Integer.parseInt(st.nextToken()));
            projetos.put(nome, new_node);
        }

        int num_arestas = Integer.parseInt(input.nextLine());

        for(int i = 0; i < num_arestas; i ++){
            String temp = input.nextLine();
            StringTokenizer st = new StringTokenizer(temp, " ");

            String node_partida = st.nextToken();
            String node_destino = st.nextToken();
            int custo = Integer.parseInt(st.nextToken());

            Node partida = projetos.get(node_partida);
            partida.arestas.add(new Aresta (node_destino, custo));

        }
    }
}
