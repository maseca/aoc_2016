import java.math.BigInteger;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Pathfinder extends JPanel
						implements ActionListener{
	protected JButton init, findPath;
	protected JTextField textField;
	protected JTextArea textArea;
	private final static String newline = "\n";
	
	private final int INPUT = 1362;
	private final int RANGE = 42;
	private final int DESTX = 31;
	private final int DESTY = 39;

	private char[][] map = new char[RANGE][RANGE];

	
	public Pathfinder(){
		super(new GridBagLayout());

		textArea = new JTextArea(RANGE,RANGE);
		textArea.setFont(new Font("monospaced", Font.PLAIN, 12));
		textArea.setEditable(false);
		JScrollPane scrollPane = new JScrollPane(textArea);

		GridBagConstraints c = new GridBagConstraints();
		c.gridwidth = GridBagConstraints.REMAINDER;

		c.fill = GridBagConstraints.BOTH;
		c.weightx = 1.0;
		c.weighty = 1.0;
		add(scrollPane, c);

		init = new JButton("INIT");
		init.setVerticalTextPosition(AbstractButton.CENTER);
		init.setHorizontalTextPosition(AbstractButton.LEADING);
		init.setMnemonic(KeyEvent.VK_M);
		init.setActionCommand("init");
		init.addActionListener(this);

		findPath = new JButton("FIND PATH");
		findPath.setMnemonic(KeyEvent.VK_F);
		findPath.setActionCommand("find path");
		findPath.addActionListener(this);
		findPath.setEnabled(false);

		init.setToolTipText("INIT");
		findPath.setToolTipText("FIND PATH");

		add(init);
		add(findPath);
	}

	public void actionPerformed(ActionEvent e){
		if("init".equals(e.getActionCommand())){
			findPath.setEnabled(true);
			for(int i = 0; i < RANGE; ++i)
				for(int j = 0; j < RANGE; ++j)
					if(isWall(j, i, INPUT))
						map[i][j] = '#';
					else
						map[i][j] = '.';

			StringBuilder builder = new StringBuilder();
			for(int i = 0; i < RANGE; ++i){
				for(int j = 0; j < RANGE; ++j){
					builder.append(map[i][j]);
				}
				builder.append(newline);
			}    
			
			textArea.setText(builder.toString());
			textArea.append(newline + "# = Wall . = Open");
			textArea.setCaretPosition(textArea.getDocument().getLength());

			/*
			for(int i = 0; i < RANGE; ++i)
				System.out.println(map[i]);
			*/
		}else if("find path".equals(e.getActionCommand())){
			findPath.setEnabled(false);
			String output = "Minimum Steps: " + minSteps(map,DESTX,DESTY,RANGE);

			StringBuilder builder = new StringBuilder();
			for(int i = 0; i < RANGE; ++i){
				for(int j = 0; j < RANGE; ++j){
					builder.append(map[i][j]);
				}
				builder.append(newline);
			}    
			
			textArea.setText(builder.toString());
			textArea.append(newline + output);
			textArea.setCaretPosition(textArea.getDocument().getLength());
		}
	}

	private static void createAndShowGUI(){
		JFrame frame = new JFrame("Pathfinder");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JLabel label = new JLabel("Pathfinder");
		frame.getContentPane().add(label);

		Pathfinder newContentPane = new Pathfinder();
		newContentPane.setOpaque(true);
		frame.setContentPane(newContentPane);

		frame.pack();
		frame.setVisible(true);
	}

	public static void main(String[] args){
		javax.swing.SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				createAndShowGUI();
			}
		});
	}

	public static boolean isWall(int x, int y, int input){
		int count, strlen;
		BigInteger total = new BigInteger("0");
		String bin;
		
		count = 0;
		total = total.valueOf(x * x + 3 * x + 2 * x * y + y + y * y + input);
		bin = total.toString(2);
		strlen = bin.length();

		for(int i = 0; i < strlen; ++i)
			if(bin.charAt(i) == '1')
				++count;
		if(count % 2 == 0)
			return false;
		else
			return true;
	}


	public static void makeNeighbors(Deque<Node> unv, ArrayList<Node> vis, char[][] mz, int range){
		int pX = unv.getLast().posX;
		int pY = unv.getLast().posY;
		int d = unv.getLast().distance;
		boolean isDupe = false;
		int size = vis.size();

		for(int i = 0; i < size; ++i)
			if(pX == vis.get(i).posX && pY == vis.get(i).posY)
				isDupe = true;

		if(!isDupe){
			if(pY > 0 && mz[pY-1][pX] == '.')
				unv.push(new Node(pX,pY-1,d+1));
			if(pX > 0 && mz[pY][pX-1] == '.')
				unv.push(new Node(pX-1,pY,d+1));
			if(pY < range-1 && mz[pY+1][pX] == '.')
				unv.push(new Node(pX,pY+1,d+1));
			if(pX < range-1 && mz[pY][pX+1] == '.')
				unv.push(new Node(pX+1,pY,d+1));

			vis.add(new Node(pX, pY, d));
			mz[pY][pX] = 'O';
		}
		unv.removeLast();

	}

	public static int minSteps(char[][] maze, int destX, int destY, int ran){
		Deque<Node> unvisited = new ArrayDeque<Node>();
		ArrayList<Node> visited = new ArrayList<Node>();
		int vsize;

		unvisited.add(new Node(1,1,0));

		do{
			makeNeighbors(unvisited, visited, maze, ran);
			vsize = visited.size();
		}while(visited.get(vsize-1).posX != destX || visited.get(vsize-1).posY != destY);
		
		maze[destY][destX] = 'X';

		return visited.get(vsize-1).distance;
	}
}
