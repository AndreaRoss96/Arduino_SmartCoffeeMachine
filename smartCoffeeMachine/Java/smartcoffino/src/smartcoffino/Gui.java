package smartcoffino;

import java.awt.Toolkit;

import com.sun.xml.internal.ws.resources.SenderMessages;

import javafx.application.Application;
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
	private static Label messages = new Label("ciao");
//	private CommChannel channel;
	private int sugarValue;
	private Button but; 
	
	@Override
	public void start(final Stage stage) throws Exception {
//		channel = new SerialCommChannel("COM8", 9600);
		
		createForm(stage);
		
//		System.out.println("Waiting Arduino for rebooting...");		
//		Thread.sleep(4000);
//		System.out.println("Ready.");
		
//		while (true) {
//			int msg = Integer.parseInt(channel.receiveMsg());
//			if(msg > 1 && msg <8) {
//				sugarValue=msg-2;
//			}else {
//				switch(msg) {
//			
//				case 1 :
//					printMessage("Welcome!");
//					break;
//				case 8 :
//					printMessage("making coffee! :)");
//					making();
//					break;
//				case 9 :
//					printMessage("the coffee is ready! :D");
//					finish();
//					break;
//				case 10 :
//					printMessage("no more coffee. Waiting for recharge");
//					maintenance();
//					break;
//				default :
//					printMessage("internal errorrrrrr");
//					break;
//					}
//			}
//			Thread.sleep(100);
//		}
		
	}
	
	private void createForm(final Stage stage) {
		layout = new AnchorPane();		
		final Label title = new Label("Smart coffee");
		AnchorPane.setTopAnchor(title, HEIGHT/20);
		AnchorPane.setLeftAnchor(title, WIDTH/2.20);
//	Label message = new Label("Message:");
		Label sugarLevel = new Label("SugarLevel: " + sugarValue);
		Label coffe = new Label("coffe");
		but = new Button("refill");
		but.setDisable(true);
		but.setOnAction(e->{
			serialSend(NUMERO_CAFE);
		});
//		AnchorPane.setTopAnchor(message, HEIGHT/6);
//		AnchorPane.setLeftAnchor(message, WIDTH/18);
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
		
		layout.getChildren().addAll(title,sugarLevel,coffe,messages, /*message,*/ but);

		scene = new Scene(layout, WIDTH, HEIGHT);
		stage.setScene(scene);
		stage.setOnCloseRequest((e) -> {
			System.exit(0);
		});
		stage.show();
	}
	
	public static void printMessage(String msg) {
		System.out.println("Mostro " +msg);	
		messages.setText(msg);
	}
	
	private void serialRecive() throws Exception {
//		
//		System.out.println("Waiting Arduino for rebooting...");		
//		Thread.sleep(4000);
//		System.out.println("Ready.");
//		
//		while (true) {
//			int msg = Integer.parseInt(channel.receiveMsg());
//			if(msg > 1 && msg <8) {
//				sugarValue=msg-2;
//			}else {
//				switch(msg) {
//			
//				case 1 :
//					printMessage("Welcome!");
//					break;
//				case 8 :
//					printMessage("making coffee! :)");
//					making();
//					break;
//				case 9 :
//					printMessage("the coffee is ready! :D");
//					finish();
//					break;
//				case 10 :
//					printMessage("no more coffee. Waiting for recharge");
//					maintenance();
//					break;
//				default :
//					printMessage("internal errorrrrrr");
//					break;
//					}
//			}
//			Thread.sleep(100);
//		}
	}
	
	private void maintenance() {
		but.setDisable(false);
	}
	private void making() {
		
	}
	
	private void finish() {
		
	}
	private void serialSend(String msg) {
//		channel.sendMsg(msg);
	}
}

	
