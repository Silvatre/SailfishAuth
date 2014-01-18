package pl.silvatre.sailfishauth;

import org.apache.commons.codec.binary.Base32;

import pl.silvatre.sailfishauth.services.TOTP;

/**
 * Startup class with main method.
 * 
 * @author Micha³ K.
 * @since 1.0
 * 
 */
public class Main {

	public static void main(String[] args) throws InterruptedException{
		Base32 codec = new Base32();
        String secretBase32 = "v54v7fqfqudv4mbacilyifwf7nhmzzyl";
        byte[] secretHex = codec.decode(secretBase32.toUpperCase());
        
        while (true) {
        	Thread.sleep(1000L);
        	long secsPassed = System.currentTimeMillis();
        	long interval = secsPassed / 30000L;
        	String intervalInHex = Long.toHexString(interval);
        	String generatedCode = TOTP.generateTOTP(secretHex, Long.toHexString(System.currentTimeMillis() / 30000L).toUpperCase(), "6", "HmacSHA1");
        	System.out.println("Code: " + generatedCode + "\n");
        }
        
	}

}
