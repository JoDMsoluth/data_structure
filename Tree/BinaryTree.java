import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTree {
	private TreeNode root;
	
	private class TreeNode {
		private TreeNode left;
		private TreeNode right;
		private int data; // Generic type
		
		public TreeNode(int data) {
			this.data = data;
		}
	}
	
	// 이진 트리 생성
	public void createBinaryTree() {
		TreeNode first = new TreeNode(1);
		TreeNode second = new TreeNode(2);
		TreeNode third = new TreeNode(3);
		TreeNode forth = new TreeNode(4);
		TreeNode fifth = new TreeNode(5);
		
		root = first; // root ---> first
		first.left = second;
		first.right = third; // second <--- first ----> third
		
		second.left = forth; 
		second.right = fifth;
	}
	
	// 전위 순회 (재귀 방식)
	public void RecursivePreOrder(TreeNode root) {
		if(root == null) {
			return;
		}
		
		System.out.println(root.data + " ");
		RecursivePreOrder(root.left);
		RecursivePreOrder(root.right);
	}
	
	// 전위 순회 (반복문 방식) - stack활용
	public void IterativePreOrder() {
		if(root == null) {
			return;
		}
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		
		while(!stack.isEmpty()) {
			TreeNode temp = stack.pop();
			System.out.println(temp.data + "");
			
			if(temp.right != null) {
				stack.push(temp.right);
			}
			if(temp.left != null) {
				stack.push(temp.left);
			}
		}
		
	}

	// 중위 순회 (재귀 방식)
	public void RecursiveInOrder(TreeNode root) {
		if(root == null) {
			return;
		}
		RecursiveInOrder(root.left);
		System.out.println(root.data + " ");
		RecursiveInOrder(root.right);
	}
	
	// 중위 순회 (반복문 방식) - 스택 사용
	public void IterativeInOrder(TreeNode root) {
		if(root == null) {
			return;
		}
		Stack<TreeNode> stack = new Stack<>();
		TreeNode temp = root;
		
		while(!stack.isEmpty() || temp != null) {
			if(temp != null) {
				stack.push(temp);
				temp = temp.left;
			} else {
				temp = stack.pop();
				System.out.println(temp.data + " ");
				temp = temp.right;
			}
		}
	}
	
	// 후위 순회 (재귀방식)
	public void ReculsivePostOrder(TreeNode root) {
		if(root == null) {
			return;
		}
		ReculsivePostOrder(root.left);
		ReculsivePostOrder(root.right);
		System.out.println(root.data + " ");
	}
	

	public void levelOrder(TreeNode root) {
		if(root == null) {
			return;
		}
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		
		while(!queue.isEmpty()) {
			TreeNode temp = queue.poll();
			System.out.println(temp.data + " ");
			if(temp.left != null) {
				queue.offer(temp.left);
			}
			if(temp.right != null) {
				queue.offer(temp.right);
			}
		}
	}
	
	public int findMax() {
		return findMax(root);
	}
	
	public int findMax(TreeNode root) {
		if(root == null) {
			return Integer.MIN_VALUE;
		} 
		
		int result = root.data;
		int left = findMax(root.left);
		int right = findMax(root.right);
		
		if(left > result) {
			result = left;
		}

		if(right > result) {
			result = right;
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		BinaryTree bt = new BinaryTree();
		bt.createBinaryTree();
		System.out.println(bt.findMax(bt.root));
	}
}