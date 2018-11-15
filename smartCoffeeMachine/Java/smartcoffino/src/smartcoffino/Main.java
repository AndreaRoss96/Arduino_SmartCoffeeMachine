package smartcoffino;

import javafx.application.Application;

public class Main {

	public static void main(String[] args) {
		MessageManager myManager = new MessageManager();
		Thread t = new Thread(myManager);
		t.start();
		
		Application.launch(Gui.class, args);
	}

}
