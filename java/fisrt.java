import javax.script.ScriptEngine; 
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;   /**  * 直接调用js代码  */
public class fisrt
{
	public static void main(String[] args)
	{
		ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("javascript");
          try {    
          String aa="3+4-7*8";
            aa=engine.eval(aa).toString();
            System.out.println(aa);
          } catch (ScriptException e) {
              e.printStackTrace();   
          }        
	}
}