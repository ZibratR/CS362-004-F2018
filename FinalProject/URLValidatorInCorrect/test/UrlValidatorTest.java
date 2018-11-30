//  FinalProjectB - zibratr and dongv

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
//Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {

   
   @Test
   public void testManualTest(){
//You can use this function to implement your manual testing
	   System.out.println("Manual test of single URL:");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));   
	   for (int i = 0; i < value.length; i++) {
	   if (urlVal.isValid(value[i])) {
       		System.out.println(value[i] + " is valid\n");
        } else {
            System.out.println(value[i] + " is invalid\n");
        }
	   }
   }
   
        // 3rd Group Member no present - Instructor ok'ed to skip partition testing.

   
   // Programming / Unit test
   

   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   int passes = 0;
   int fails = 0;
   int tests = 0;
   int expectedFails = 0;
   int expectedPasses = 0;
   int unexpectedResults = 0;
   
   @Test
   public void programmingTest()
   {
        // SCHEME
        System.out.println("\tFIRST test: Scheme\n");
        runTest("http://www.google.com", true);
        runTest("http:/www.google.com", false);
        runTest("http:///www.google.com", false);
        runTest("hppp:/www.google.com", false);
        runTest("http//www.google.com", false);
        runTest("http:://www.google.com", false);

        // AUTHORITY
        System.out.println("\tSECOND test: Authority\n");
        runTest("http://www.google.com", true);
        runTest("http://go.1aa", false);
        runTest("http://www", false);
        runTest("http://1.2.3", false);
        
        // PORT
        System.out.println("\tTHIRD test: Port\n");
        runTest("http://www.google.com:65535", true);
        runTest("http://www.google.com:65536", false);
        runTest("http://www.google.com:6ef", false);
        runTest("http://www.google.com:r", false);
            
        // PATH
        System.out.println("\tFOURTH test: Path\n");
        runTest("http://www.google.com:65535/test1", true);
        runTest("http://www.google.com:65535/$23", true);
        runTest("http://www.google.com:65535//test1", false);
        runTest("http://www.google.com:65535/test1//1", false);
        runTest("http://www.google.com:65535/../", false);
       
        // QUERY
        System.out.println("\tFIFTH test: Query\n");
        runTest("http://www.google.com:65535/test1?action=view", true);
        runTest("http://www.google.com:65535/test1?action==view", false);
        runTest("http://www.google.com:65535/test1??action=view", false);
        runTest("http://www.google.com:65535/test1.action=view", false);
        runTest("http://www.google.com:65535/test1-action=view", false);
            
        // NULL
        System.out.println("\tSIXTH test: Null and Empty URL\n");
        runTest(null, false);
        runTest("", false);

        System.out.println("\nExpected PASSES: " + expectedPasses + "\t\tExpected FAILS: " + expectedFails);
        System.out.println("TOTAL PASSES: " + passes + "\t\t\tTOTAL FAILS: " + fails);
        System.out.println("*** Unexpected results: " + unexpectedResults + "\n");
   }
   
   private void runTest(String urlValue, boolean expectedResult) 
   {
	   System.out.println("Testing: " + urlValue);
	   tests++;
	   boolean result = urlVal.isValid(urlValue);
	   
	   //assertEquals(result, expectedResult);
	   
	   if (result)
       {
           System.out.println("Result: PASS");
           passes++;
       }
       else
       {
           System.out.println("Result: FAIL");
           fails++;
       }
	   
       if(expectedResult) 
       {
    	   System.out.println("Expected: PASS");
    	   expectedPasses++;
       }
       else 
       {
    	   System.out.println("Expected: FAIL");
    	   expectedFails++;
       }
       
       if (result != expectedResult)
       {
           System.out.println("*** Unexpected Result for " + urlValue);
           unexpectedResults++;
       }
       
       System.out.println("\n");
   }
   
//array of URL to be tested by manual test function
String[] value = {"http://www.google.com:80","http://www.amazon.com", "http://www.google.com:80/test1/", "www.amazon.com", "http://www.amazon.com/test1?action=edit&mode=up"};


   
}
