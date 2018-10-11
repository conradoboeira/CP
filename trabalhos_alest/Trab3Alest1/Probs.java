import java.util.*;

public class Probs {

	private Node root;
	private List<Node> floresta; 

	public  class Node{
		
		private double data;
		private String nome;
		private Node irmao;
		private Node filho;

		Node(String n, double d){
			data = d;
			nome = n;
			irmao = null;
			filho = null;
		}
	}
	public Probs(){
		root = null;
		floresta = new ArrayList<Node>();
	}

	public void add(String n, double d, String pai){
		Node aux = find(root,pai);
		if(aux == null){
			System.out.println("novo pai " + pai);
			addPai(pai,1);
			aux = root;
		} 
		Node novo = new Node (n, d);
		novo.irmao = aux.filho;
		aux.filho = novo;
	}

	public void addPai(String n, double d){
		if(root == null){
			root = new Node(n,d);
		}
		else{
			floresta.add(root);
			root = new Node(n,d);
		}
	}

	public  Node find(Node n, String nome){
		if( n == null) return null;
		if(n.nome.equals(nome)) return n;
		Node f = n.filho;
		while(f != null){
			Node aux = find(f, nome);
			if (aux != null) return aux;
			f = f.irmao;
		}
		return null;
	}

	public void atualiza(){
		List<Node> usados = new ArrayList<Node>();
		for(Node n : floresta){
			Node aux = find(root, n.nome);
			if(aux!= null){
				aux.filho = n.filho;
				usados.add(n);
			}
		}
		floresta.removeAll(usados);
	}

	public void atualizaProbs(){
		atualizaProbsp(root);
	}

	private void atualizaProbsp(Node n){
		if(n.filho == null) return;
		Node f = n.filho;
		while(f != null){
			f.data = f.data * n.data;
			atualizaProbsp(f);
			f = f.irmao;
		}
	}

	public void findMaiorProbs(){
		//double p = findMaiorProbs(root, 0.0);
		Node aux = new Node("", 0.0);
		Node resp =  findMaiorProbs(root, aux);
		System.out.println(resp.nome + ": " + resp.data*100 + "%");
		//if(aux == null) return "Fodeu";
		//return aux.nome;
	}

	public  Node findMaiorProbs(Node n, Node maior){
		//Node maior = n;
		//String nMaior = s;
		if(n.filho == null && n.data > maior.data){
			maior = n;
			//nMaior = n.nome;
		} 
		Node f = n.filho;
		while(f != null){
		 	maior = findMaiorProbs(f, maior);
			f = f.irmao;
		}
		return maior;
	}

	public  void print( ) {
    	print( root, "" );
  	}

  	private void print( Node n, String s ) {
    	if ( n == null ) return;
    	s = s + "	";
    	System.out.println(s + n.nome + " " + n.data*100);
    	Node f = n.filho;
		while(f != null){
			print(f, s);
			f = f.irmao;
		}
  	}

}