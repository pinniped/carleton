import java.util.Random;

/** A demonstration of the class SearchArray.
    @author Charles Hoot
    @version 3.0
*/
public class Driver
{
	
   public static void main(String args[])
   {
      Random generator = new Random();

      final int MAXROW = 5;
      final int MAXCOL = 7;

      // final int MAXROW = 37;
      // final int MAXCOL = 27;

      // generate a random array of integers
      Integer data[][] = new Integer[MAXROW][MAXCOL];
      for (int r = 0; r < MAXROW; r++)
         for (int c = 0; c < MAXCOL; c++)
         {
             Integer value = generator.nextInt(10);
             data[r][c] = value;
             
             // guarantee is >= to value below it
             if (r > 0 && data[r][c] < data[r-1][c])
                 data[r][c] += data[r-1][c];
             // guarantee is >= to value left of it
             if (c > 0 && data[r][c] < data[r][c-1])
                 data[r][c] += data[r][c-1];
         }     

      System.out.println("The array is:");  
      for (int r = 0; r < MAXROW; r++)
      {
         for (int c = 0; c < MAXCOL; c++)
         {
             System.out.print(data[r][c] + "  ");
         }
         System.out.println();
      }

      System.out.println("Verify that we can find the data in each of the corners");
      System.out.println("Each of the following should be found in the array");
      System.out.println("Found data[0][0] is " + SearchArray.search(data, new Integer(data[0][0])));
      System.out.println("Found data[0][MAXCOL-1] is " + SearchArray.search(data, new Integer(data[0][MAXCOL-1])));
      System.out.println("Found data[MAXROW-1][0] is " + SearchArray.search(data, new Integer(data[MAXROW-1][0])));
      System.out.println("Found data[MAXROW-1][MAXCOL-1] is " + SearchArray.search(data, new Integer(data[MAXROW-1][MAXCOL-1])));

      System.out.println("Verify that we can find every data value in the array");
      boolean foundAll = true;
      for (int r = 0; r < MAXROW; r++)
      {
         for (int c = 0; c < MAXCOL; c++)
         {
             if (SearchArray.search(data, new Integer(data[0][MAXCOL-1])) != true)
             {
                 foundAll = false;
                 System.out.println("Could not find data at [" + r + "[]" +c+"]");
             }   
         }
      }

      if (foundAll)
         System.out.println("Found them all");
         
      System.out.println("Verify that we don't find anything that isn't in the array");
      boolean allMatch = true;
      for (int value = data[0][0]-100; value < data[MAXROW-1][MAXCOL-1] + 100; value++)
         if (SearchArray.search(data, new Integer(value)) != SearchArray.bruteForceSearch(data, new Integer(value)))
         {
             allMatch = false;
             System.out.println("Search failed on data " + value);
         }
         
      if(allMatch)
         System.out.println("Everything worked");
   } // end main
} // end Driver

/*
The array is:
0  2  2  3  4  9  12  15  22  30  37  45  48  48  50  50  51  56  57  63  65  66  73  78  80  89  90  
7  13  19  22  28  43  62  84  106  136  178  223  280  333  388  446  499  562  625  691  759  833  909  994  1077  1175  1270  
11  14  21  27  29  45  71  84  112  138  183  224  283  342  395  450  503  562  634  697  759  836  912  998  1085  1176  1277  
19  23  45  77  108  153  227  319  431  576  763  992  1279  1629  2033  2487  2994  3564  4206  4912  5679  6518  7430  8432  9520  10701  11983  
28  32  47  85  110  156  234  323  439  582  766  992  1279  1631  2035  2492  2994  3566  4212  4919  5687  6518  7439  8434  9520  10701  11986  
28  35  49  89  117  163  235  328  447  587  771  992  1285  1631  2041  2495  2998  3573  4212  4921  5696  6525  7441  8440  9528  10709  11990  
34  35  51  95  123  171  240  335  455  589  771  998  1294  1640  2045  2500  3007  3581  4217  4921  5696  6528  7446  8447  9532  10712  11996  
34  43  57  97  125  172  249  336  457  597  771  1005  1297  1649  2046  2508  3014  3590  4218  4923  5697  6528  7450  8447  9532  10713  12003  
37  52  64  100  132  175  252  337  458  604  775  1007  1300  1658  2050  2508  3016  3596  4220  4926  5698  6530  7457  8447  9533  10718  12011  
40  57  68  104  135  183  257  346  459  608  781  1010  1301  1666  2056  2516  3020  3599  4223  4931  5702  6536  7466  8454  9538  10727  12019  
43  59  76  107  138  184  265  354  468  612  790  1013  1308  1668  2057  2521  3026  3599  4226  4936  5710  6540  7469  8463  9541  10735  12021  
46  66  82  107  147  189  271  355  476  616  797  1018  1309  1677  2066  2526  3026  3600  4226  4938  5718  6547  7477  8472  9544  10744  12026  
51  67  82  109  154  191  280  356  479  625  804  1026  1315  1678  2070  2529  3030  3600  4232  4939  5726  6552  7483  8480  9549  10745  12032  
60  70  87  118  158  195  281  356  487  627  806  1034  1322  1685  2073  2529  3035  3609  4235  4945  5728  6560  7483  8487  9557  10746  12035  
61  79  88  121  165  199  285  365  494  635  815  1034  1325  1693  2079  2535  3044  3617  4237  4947  5731  6567  7490  8495  9561  10755  12037  
63  79  96  126  170  206  291  369  503  641  822  1037  1328  1699  2085  2535  3053  3625  4239  4950  5736  6571  7498  8496  9567  10759  12042  
63  81  101  127  170  214  292  376  507  648  823  1045  1332  1706  2087  2536  3056  3627  4239  4956  5742  6577  7505  8501  9567  10763  12043  
63  90  110  134  179  223  297  384  509  655  823  1045  1340  1707  2096  2545  3058  3636  4244  4965  5748  6584  7511  8501  9576  10766  12048  
65  93  118  135  186  229  303  390  515  659  828  1050  1341  1713  2102  2548  3065  3640  4244  4972  5752  6593  7520  8501  9577  10773  12055  
73  96  125  141  191  229  306  393  519  661  832  1053  1346  1714  2107  2557  3071  3641  4248  4981  5755  6600  7525  8503  9577  10782  12063  
82  103  134  147  191  234  307  394  526  667  835  1054  1352  1718  2115  2561  3078  3643  4249  4985  5756  6607  7528  8508  9584  10782  12065  
90  106  142  149  191  235  309  395  531  670  844  1061  1353  1723  2124  2561  3084  3648  4249  4986  5763  6611  7536  8517  9586  10786  12068  
97  115  147  158  194  236  316  395  534  676  845  1066  1359  1725  2129  2564  3092  3654  4258  4995  5772  6617  7537  8523  9590  10793  12070  
99  116  155  161  202  242  318  396  538  676  849  1071  1363  1730  2136  2569  3094  3656  4263  5002  5779  6619  7544  8532  9593  10801  12074  
103  122  159  167  207  244  321  404  545  678  856  1080  1364  1739  2145  2569  3097  3657  4271  5008  5781  6627  7553  8540  9598  10807  12078  
108  127  160  170  208  252  321  408  550  683  856  1087  1372  1748  2147  2577  3102  3658  4278  5009  5788  6627  7555  8544  9598  10807  12080  
113  132  164  177  213  257  323  417  558  688  862  1095  1380  1755  2152  2578  3111  3664  4278  5012  5790  6632  7562  8547  9602  10809  12086  
116  141  169  185  213  257  327  426  564  696  870  1102  1383  1757  2158  2580  3117  3671  4287  5017  5798  6636  7570  8550  9606  10811  12091  
120  141  175  190  220  258  329  434  569  704  879  1109  1388  1758  2161  2581  3125  3678  4295  5021  5803  6637  7576  8554  9615  10819  12097  
121  147  180  197  228  260  336  435  577  708  885  1117  1395  1766  2170  2582  3125  3683  4300  5025  5804  6643  7576  8560  9620  10822  12103  
122  154  183  199  233  260  344  443  584  714  886  1126  1395  1767  2175  2591  3131  3688  4300  5029  5806  6652  7581  8561  9625  10823  12111  
128  157  190  202  234  269  349  443  593  718  889  1130  1401  1772  2178  2596  3132  3691  4304  5034  5808  6654  7589  8570  9626  10827  12120  
136  160  191  204  236  275  351  443  599  720  896  1135  1405  1779  2183  2599  3140  3697  4308  5034  5817  6658  7591  8572  9626  10836  12125  
141  168  199  205  236  276  357  451  600  727  904  1137  1413  1787  2189  2606  3148  3703  4310  5042  5823  6659  7597  8576  9631  10837  12134  
145  175  206  211  244  279  362  454  609  730  905  1140  1419  1792  2194  2614  3151  3710  4318  5046  5831  6667  7600  8582  9633  10838  12139  
149  179  210  213  253  286  370  457  615  735  914  1148  1420  1799  2194  2617  3155  3716  4327  5055  5840  6670  7604  8585  9638  10841  12143  
149  184  211  213  261  295  377  461  616  735  915  1155  1422  1801  2199  2619  3160  3725  4332  5055  5847  6671  7605  8592  9646  10848  12143  
Verify that we can find the data in each of the corners
Each of the following should be found in the array
Found data[0][0] is true
Found data[0][MAXCOL-1] is true
Found data[MAXROW-1][0] is true
Found data[MAXROW-1][MAXCOL-1] is true
Verify that we can find every data value in the array
Found them all
Verify that we don't find anything that isn't in the array
Everything worked
*/
