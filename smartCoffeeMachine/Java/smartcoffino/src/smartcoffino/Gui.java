package smartcoffino;

import java.awt.Toolkit;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

/**
 * JavaFX entry point, it launches the main menu.
 */

public class Gui extends Application{
	final double HEIGHT = Toolkit.getDefaultToolkit().getScreenSize().getHeight() / 2;
	final double WIDTH = Toolkit.getDefaultToolkit().getScreenSize().getWidth() / 3;
	private Scene scene;
	private AnchorPane layout;
	private Label messages = new Label("ciao");
	//private int sugarValue;
	//private int coffeLevel
	
	
	@Override
	public void start(final Stage stage) throws Exception {
		layout = new AnchorPane();
		Label title = new Label("Smart coffee");
		AnchorPane.setTopAnchor(title, HEIGHT/20);
		AnchorPane.setLeftAnchor(title, WIDTH/2.20);
		Label message = new Label("Message:");
		Label sugarLevel = new Label("SugarLevel:");
		Label coffe = new Label("coffe");
		Button but = new Button("refill");
		but.setDisable(true);
		
		AnchorPane.setTopAnchor(message, HEIGHT/6);
		AnchorPane.setLeftAnchor(message, WIDTH/18);
		AnchorPane.setTopAnchor(messages, HEIGHT/6);
		AnchorPane.setLeftAnchor(messages, WIDTH/2.1);

		/*AnchorPane.setTopAnchor(sugar, HEIGHT/9);
		AnchorPane.setLeftAnchor(sugar, WIDTH/18);*/
		AnchorPane.setTopAnchor(sugarLevel, HEIGHT/3.5);
		AnchorPane.setLeftAnchor(sugarLevel, WIDTH/18);
		
		AnchorPane.setBottomAnchor(but, HEIGHT/20);
		AnchorPane.setLeftAnchor(but, WIDTH/2.0);
		
		AnchorPane.setTopAnchor(coffe, HEIGHT/2.5);
		AnchorPane.setLeftAnchor(coffe, WIDTH/18);
		/*AnchorPane.setTopAnchor(coffeLevel, HEIGHT/9);
		AnchorPane.setLeftAnchor(coffeLevel, WIDTH/2.25);*/
		
		layout.getChildren().addAll(title,sugarLevel,coffe,messages,message,but);

		scene = new Scene(layout, WIDTH, HEIGHT);
		stage.setScene(scene);
		stage.setOnCloseRequest((e) -> {
			System.exit(0);
		});
		stage.show();
	}
	
	private void printMessage(String msg) {
		messages.setText(msg);
	}
	
	private void serialRecive() {
		
		
	}
	private void serialSend(String msg) {
		
	}
}

	
