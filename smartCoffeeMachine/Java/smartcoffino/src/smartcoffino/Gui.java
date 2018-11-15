package smartcoffino;

import java.awt.Toolkit;
import java.net.URL;

import com.sun.xml.internal.ws.resources.SenderMessages;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
//import modulo_lab_2_2.msg.jssc.*;

/**
 * JavaFX entry point, it launches the main menu.
 */

public class Gui extends Application {
	final double HEIGHT = Toolkit.getDefaultToolkit().getScreenSize().getHeight() / 2;
	final double WIDTH = Toolkit.getDefaultToolkit().getScreenSize().getWidth() / 3;
	private static final String NUMERO_CAFE = "2";
	private Scene scene;
	private AnchorPane layout;
	private Label messages = new Label("...");
	private Label sugarValue;
	private Button but; 
	private MessageManager myManager;
	
	@Override
	public void start(final Stage stage) throws Exception {		
		createForm(stage);
		myManager = new MessageManager(this);
		Thread t = new Thread(myManager);
		t.start();		
	}
	
	private void createForm(final Stage stage) {
		layout = new AnchorPane();		
		final Label title = new Label("Smart coffee");
		title.getStyleClass().add("title");
		sugarValue = new Label("");
		Label subtitle = new Label("Message:");
		Label sugarLevel = new Label("SugarLevel: ");
		but = new Button("refill");
		but.setDisable(true);
		but.setOnAction(e->{
			myManager.send("refill" + NUMERO_CAFE);
			printMessage("Coffe refilled: " + NUMERO_CAFE);
			but.setDisable(true);
		});
		
		AnchorPane.setTopAnchor(title, HEIGHT/20);
		AnchorPane.setLeftAnchor(title, WIDTH/2.80);
		
		AnchorPane.setTopAnchor(subtitle, HEIGHT/6);
		AnchorPane.setLeftAnchor(subtitle, WIDTH/18);
		AnchorPane.setTopAnchor(messages, HEIGHT/6);
		AnchorPane.setLeftAnchor(messages, WIDTH/2.2);

		AnchorPane.setTopAnchor(sugarValue, HEIGHT/3.5);
		AnchorPane.setLeftAnchor(sugarValue, WIDTH/4);
		AnchorPane.setTopAnchor(sugarLevel, HEIGHT/3.5);
		AnchorPane.setLeftAnchor(sugarLevel, WIDTH/18);
		
		AnchorPane.setBottomAnchor(but, HEIGHT/20);
		AnchorPane.setLeftAnchor(but, WIDTH/2.50);
		
		
		
		layout.getChildren().addAll(title,sugarLevel,messages, subtitle, but, sugarValue);

		scene = new Scene(layout, WIDTH, HEIGHT);
		URL url = this.getClass().getResource("style.css");
	    if (url == null) {
	        System.out.println("Resource not found. Aborting.");
	        System.exit(-1);
	    }
	    String css = url.toExternalForm(); 
	    scene.getStylesheets().add(css);
		stage.setScene(scene);
		
		stage.setOnCloseRequest((e) -> {
			System.exit(0);
		});
		stage.setResizable(false);
		stage.show();
	}
	
	public void printMessage(String msg) {
		System.out.println(msg);	
		messages.setText(msg);
		System.out.println(messages.getText());	
	}
	
	public void maintenance() {
		but.setDisable(false);
		myManager.send(NUMERO_CAFE);
	}
	
	public void setSugar(int value) {
		sugarValue.setText("" + value);
	}
}

	
