#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/arr.h"

namespace leetcode::arr::tests
{
    class two_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( two_sum_tests, case1 )
    {
        const auto numbers = { 2, 7, 11, 15 };
        const auto target = 9;

        const auto actual = target_two_sum::two_sum1( numbers, target );
        const auto expected = std::vector<int>{ 0, 1 };
    	
        EXPECT_EQ( actual, expected );
    }

    class maximum_two_prod_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( maximum_two_prod_tests, case1 )
    {
        auto input = std::vector<int>{ 3, 4, 5, 2 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case2 )
    {
        auto input = std::vector<int>{ 1, 5, 4, 5 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 16;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case3 )
    {
        auto input = std::vector<int>{ 3, 7 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case4 )
    {
        auto input = std::vector<int>{ 3, 7 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case5 )
    {
        auto input = std::vector<int>{ 1, 2, 5, 3, 6 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 20;

        EXPECT_EQ( actual, expected );
    }

    class contiguous_array_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( contiguous_array_tests, case1 )
    {
        const auto input = std::vector<int>{ 0, 1 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case2 )
    {
        const auto input = std::vector<int>{ 0, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case3 )
    {
        const auto input = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 26;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case4 )
    {
        const auto input = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 22;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case5 )
    {
        const auto input = std::vector<int>{ 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 20;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case6 )
    {
        const auto input = std::vector<int>{ 0, 1, 1, 0, 1, 1 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    class max_sub_array_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( max_sub_array_tests, case1 )
    {
        const auto input = std::vector<int>{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 0, -1, 0, 0, 0, -1, 0, 1 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case3 )
    {
        const auto input = std::vector<int>{ 3, -1, 0, 2 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case4 )
    {
        const auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 30;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case5 )
    {
        const auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4, 12, 4, 13, 1, 0, 1, 143 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 200;

        EXPECT_EQ( actual, expected );
    }

    class buy_and_sell_stock_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( buy_and_sell_stock_tests, case1 )
    {
        const auto input = std::vector<int>{ 7, 1, 5, 3, 6, 4 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case2 )
    {
        const auto input = std::vector<int>{ 7, 6, 4, 3, 1 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case3 )
    {
        const auto input = std::vector<int>{ 7 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case4 )
    {
        const auto input = std::vector<int>{ 7, 1, 3, 2, 9, 4 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case5 )
    {
        const auto input = std::vector<int>{ 7, 1, 3, 2, 9, 4, 2, 2, 1, 2, 6 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    class maximum_circular_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( maximum_circular_sum_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, -2, 3, -2 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case2 )
    {
        const auto input = std::vector<int>{ 5, -3, 5 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 10;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case3 )
    {
        const auto input = std::vector<int>{ 3, -1, 2, -1 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case4 )
    {
        const auto input = std::vector<int>{ 3, -2, 2, -3 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case5 )
    {
        const auto input = std::vector<int>{ -2, -3, -1 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    class subarray_product_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( subarray_product_tests, case1 )
    {
        const auto input = std::vector<int>{ 10, 5, 2, 6 };
    	
        const auto actual = subarray_product::num_subarray_product_less_than_k( input, 2 );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( subarray_product_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 3 };

        const auto actual = subarray_product::num_subarray_product_less_than_k( input, 2 );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( subarray_product_tests, case3 )
    {
        const auto input = std::vector<int>{ 10, 5, 2, 6 };

        const auto actual = subarray_product::num_subarray_product_less_than_k( input, 100 );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( subarray_product_tests, case4 )
    {
        const auto input = std::vector<int>{ 10, 5, 2, 6 };

        const auto actual = subarray_product::num_subarray_product_less_than_k( input, 1000 );
        const auto expected = 10;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( subarray_product_tests, case5 )
    {
        const auto input = std::vector<int>{ 10, 5, 2, 6 };

        const auto actual = subarray_product::num_subarray_product_less_than_k( input, 50 );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class permutation_in_string_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( permutation_in_string_tests, case1 )
    {
        const auto input = std::make_pair<std::string, std::string>( "ab", "eidbaooo" );

        const auto actual = permutation_in_string::checkInclusion( input.first, input.second );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( permutation_in_string_tests, case2 )
    {
        const auto input = std::make_pair<std::string, std::string>( "ab", "eidboaoo" );

        const auto actual = permutation_in_string::checkInclusion( input.first, input.second );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( permutation_in_string_tests, case3 )
    {
        const auto input = std::make_pair<std::string, std::string>( "adc", "dcda" );

        const auto actual = permutation_in_string::checkInclusion( input.first, input.second );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( permutation_in_string_tests, case4 )
    {
        const auto input = std::make_pair<std::string, std::string>
    	( 
            "nlrsecrfraocbgnsazsngoqjljquksbcspyuqobkpuagfbndhpstpfzatxcwscjwqnjjtlogljhyhtgrpauxnuzlrhljgdlgdpxyahgmdwytivtqccpdukhseoajdmsaozhtnrsjvyzpigvbrxdxqresnuhyzgupaijresrlhtnjkyfwpxairirkzuajnpayhbhyerfqnmwdgqmjzvrdvlsnmxitnumipyfixlzchjwgvfzpsryxxotnuoftqffmiozywskuvnjkuehevohverpbisoblzurysiaqrsqwqfncuqkqbecvrxbkrjiddmfauvetruxwqnelbufekkkwofupyssmkkobatpjthrxgwlpttfupiormualobswtzwwcnrqyxlqfrnvgeeezsacljnewfvvbtzfrvdllqrlvguiinpdxkbhqzgqafzsvvhpijjsqgnyxeoqldfrbbuadzpskrhpziuaoqrvwpionmiojuhxgkufkgaavdeujuxpmggngquxnyqhrdvpxnjwqtlnwnroswrzxxdksfvrnclwonklpomzhwldjjtyylkhgayuuzlbdgacoyhlajtpvgubvwvzmvnuibfcpncqiopzodxbbjohfswkbzgbgtubxqzjnhupkjgyduvfejonadaanactccvfebgaseupnffzflxlgafohudsieixlljnvqeyuruegqslxihourfpbmnhnbgpzxrbxvazmspkdafriouzowmxeqmbyssxgfesetheaafqvotcldddqubagloyblytrzfmkivuudpwektheznegopcdbcldnlzujzmripflhahfgtbqaqvpgyefzpdraamixdyghihyhnofzoywmhkmunvntpyqvajuqholxmdvsmcihsuqivqfbsqerzbtptadkeajuurzufdregtlrotyrozdyyjavpevabtveksdbyfwhmtxvbxbuhxpuutmqfxrrpazbpijaskmhnunntpojdfkppmrhwvvnicthcxhnpjmrgmuwuwqfhwgssdmcgiekgftestjzupqjnakclpmzazaghkosnutqekzlixovhabfsspqbwfvvenygtvmwmrqxnsqejekhzcziwgtyovpyukgcpjzxeqxjvaiffwlgiyzsmztqhmxoqolhblqhxeararaljnswlwdcfxlmehqraoobydhprasgtsesugkyqbexiilmvupjvkbmsmjqgtsyltpaeyhbwbbhrpgazokrlzcibhnbpomieavawiomsfzzkwkndihwzhrpiafrsyufpzblzpvflywmaweprthnkajvplkwfjvcsiblvucjmwcjkwsszhggczzcsfrzgadkasghstkknguodxxhzftrfrnlbrwpwrjlsecvrarjvgciymaincafmlphlibteuzhrfnldcajimjxqomljxweqhyiqtcyznpnsuzzldrladelaqopgiagjhjnsdrmlrldzebcvqxqdthxvhmzcmyczekvymbnyisppljimozszqqxymqkejfewxxihupebmydhlqldrzafehscklchzjlctmuaytuhosxruqanpchvjptbykpezxikaueufuiiujmanodulozjamqduqekihdmeizqcdtfihvijrxoazgibfhoumqriiorsbbkoscxviabqddeqfayfzqptamhojdmxbpyubixhgdhqtmtcvjzdutvbiycsmchgkaeiaxbpgkpreuhoisfptugogaquijkxnyntfututflaacniiawxbxdsghavtenvatfyfkjkeisactvkmweoeubudbekwkbhctxlqabxawclzftxqyvmdaptphftdyfspdwruohjdwsbjtjkmyaabxwrosyeswoygiilbmefqhmuhkvmgljiucorrximtkwdlcmceytuyyrmcbembghmrdzcgxgbzbcscezqamnhnkuecjehouthtpqzeuibiruvneafgizllkntztgksnvtcqklhcyvvrixabwekbjdvezwfjmdrmhiabvnwwanjxbiwhmtgjfjhofpqliigrxnfehmrpjsxsmxvgrwnmpvfxaxzkrzbqccmwizqgaousmehamsdmvibzeslwbolrfxcggviotkytewihiffdwsujqmszzoxhrnktdwefkxtnratgtgnjxjhscuqysuaeuecmsdjdbuvtemhsyygvryfqrlccstckgmtfxtiumvvgwbxotlyogvsmahfcubuywihnchkxhfexfsxteysobunucuqtjwmnnujihqecemszblrzyxmaupkjzgonsvszcslpcwluijfdrfqplpaxjcmhnwbtrlypqpguhhqosmldjtupwhfqlmwikvfruqylvkbwdfmtgcvmidiqtwigrcwdphloerrcsufbgjrulwweolbryzjbnydbjsulwawtibpxfxgtnoiomfnwjdqvjuzwfcbubuoyunlbsrdjvmccyutjksduphzyzeuxdnmejlcwzhktaudwaqqragthmvclwvrrlwfqxbstmotxjelykcthiwoeobyuvirzpvkyhuxqbfwfyspzghjddvjjrctqpvuckeessrlwzznhlmfnxxuhsrntxqysyzvfumrjjybfvhubeofcfsdimcjcunfconixdcckquifqetcoevhtzqqgtrgjlhfrxfrmzrkdrehbjmcsegbgnfwvfwqtjfalftldgzemgsntnpohnmjjfrlkkktxmjynayhqwfiqvjdqdcqhjhcgnviefsrblfvmrjdgmwkajeftvfvrlnswjcvmismwxoqzqrpelaswotetaruqvmqrfjfgcnmtafpvjkrfdhibwvbrvlypvpfjnyxllldutrqkuiikkxkccnvxkkcdmlvsoududwmszpcrxf",
            "ydwhfwwwyfuwmxkpycqwrqjwfcfpvzdzienbviuczgkoumcpeikpgtdujaraegbcqeaeetxtzbddnllxpbhgurcgcpreyfozxkuqnrabglvzugxipaepgpvplckcuvpvsmluamgwnzlilgmdpotxzyiidrmrmhyqdztpqpcirpibopxydmludvbwwoltspjcqaawalrxdxnfdnzixvhpzymajcnhwtcskauevlktuuyvtkgbzheoqcciqjsdxysmwrfamvygiofgvdesdggcccezkimvhqolyvcakalmrwmfxqdszmcaenthsbrnmvmhrjktetxziceojghzorqunkiteidnlqqfjsmfmwydydvffbiefrzcnmrqveccplbkiyybimwqznlrsecrfraocbgnsazxngoqjljquksbcspyuqobkpuagfbndhpstpfzatxcwscjwqnjjtlogljhyhtgrpauxnuzlrhljgdlgdpxyahgmdwytivtqccpdukhseoajdmsaozhtnrsjvyzpigvbrxdxqresnuhyzgupaijresrlhtnjkyfwpxairirkzuajnpayhbhyerfqnmbdgqmjzvrdvlsnmxitnumipyfixlzchjwgvfzpsryxxotnuoftqffmiozywskuvnjkuehevohverpbisoblzurysiaqrsqwqfncuqkqbecvrxakrjiddmfauvetruxwqnelbufekkkwofupyssmkkobatpjthrxgwlpttfupiormualobswtzwwcnrqyxlqfrnvgeeezsacljnewfvvbtzfrvdllqrlvguiinpdxkbhqzgqafzsvvhpinjsqgnyxeoqldfrbbuadzpskrhpziuaoqrvwpionmiojuhxgkufkgaavdeujuxpmggngquxnyqhrdvpxnjwqtlnwnroswrzxxdksfvrnclwonklpomzhwldjjtyylkhgayuuzlbdgacoyhlajtpvgubvwvzmvnuibfcpncqiopzodxbbjohfswkbzgbgtubxqzjnhupkjgyduvfejonadaanactccvfebgaseupnffzflxlgafohudsieixlljnvqeyuruegqslxihourfpbmnhnbgpzxrbxvazmspkdafriouzowmxeqmbyssxgfesetheaafqvotclddrqubagloyblytrzfmkivuudpwektheznegopcdbcldnlzujzmripflhahfgtbqaqvpgyefzpdraamixdyghihyhnofzoywmhkmunvntpyqvajuqholxmdvsmcihsuqivqfbsqerzbtptadkeajuurzufdregtlrotyrozdyyjavpevabtveksdbyfwhmtxvbxbuhxpuutmqfxrrpazbpijaskmhnunntpojdfkppmrhwvvnicthcxhnpjmrgmuwuwqfhwgssdmcgiekgftestjzupqjnakclpmzazaghkosnutqekzlixovhabfsspqbwfvvenygtvmwmrqxnsqejekhzcziwgtyovpyukgcpjzxeqxjvaiffwlgiyzsmztqhmxoqolhblqhxeararaljnswlwdcfxlmehqraoobydhprasgtsesugkyqbexiilmvupjvkbmsmjqgtsylhpaeyhbwbbhrpgazokrlzcibhnbpomieavawiomsfzzkwkndihwzhrpiafrsyufpzblzpvflywmaweprthnkajvplkwfjvcsiblvucjmwcjkwsszhggczzcsfrzgadkasghstkknguodxxhzftrfrnlbrwpwrjlsecvrarjvgciymaincafmlphlibteuzhrfnldcajimjxqomljxweqhyiqecyznpnsuzzldrladelaqoqgiagjhjnsdrmlrldzebcvqxqdthxvhmzcmyczekvymbnyisppljimozszqqxymqkejfewxxihupebmydhlqldrzafehscklchzjlctmuaytuhosxruqanpchvjptbykpezxikaueufuiiujmanodulozjamqduqekihdmeizqcdtfihvvjrxoazgibfhoumqriiorsbbkoscxviabqddeqfayfzqptamhojdmxbpyubixhgdhqtmtcvjzdutvbiycsmchgkaeiaxbpgkpreuhoisfptugogbquijkxnyntfututflaacniiawxbxdsghavtenvatfyfkjkeisactvkmweotubudbekwkbhctxlqabxawclzftxqyvmdaptphftdyfspdwruohjdwsbjtjkmyaabxwrosyeswoygiilbmefqhmuhkvmgljiucorrximtkwdlcmceytuyyrmcbembghmrdzcgxgbzbcscezqamnhnkuecjehouthtpqzeuibiruvneafgizllkntztgksnvtcqklhcyvvrixabwekbjdvezwfjmdrmhiabvnwwanjxbiwhmtgjfjhofpqliigrsnfehmrpjsxsmxvgrwnmpvfxaxzkrzbqccmwizqgaousmehamsdmvibzeslwbolrfxcggviotkytewihiffdwsujqmszzoxhrnktdwefkxtnratgtgnjxjhscuqysuaeuecmsdjdbuvtemhsyygvryfqrlccstckgmtfxtiumvvgwbxotlyogvsmahfcubuywihnchkxhfexfsxteysowunucuqtjwmnnujihqecemszblrzyxmaupkjzgonsvszcslpcwluijfdrfqplpaxjcmhnwbtrlypqpguhhqosmldjtupwhfqlmwikvfruqylvkbwdfmtgcvmidiqtwigrcwdphloerrcsufbgjrulwweolbryzjbnydbjsulwawtibpxfxgtnoiomfnwjdqvjuzwfcbubuoyunlbsrdjvmccyutjksduphzyzeuxdnmejlcwzhktaudwapqragthmvclwvrrlwfqxbstmotxjelykcthiwoeobyuvirzpikyhuxqbfwfyspzghjddvjjrctqpvuckeessrlwzznhlmfnxxuhsrntxqysyzvfumrjjybfvtubeofcfsdimcjcunfconixdcckquifqetcoevhtzqqgtrgjlhfrxfrmzrkdrehbjmcsegbgnfwvfwqtjfalftldgzemgsntnpohnmjjfrlkkktxmjynayhqwfiqvjdqdcqhjhcgnviefsrblfvmrjdgmwkajeftvfvrljswjcvmismwxoqzqrpelaswotetaruqvmqrfjfgcnmtafpvjkrfdhibwvbdvlypvpfjnyxllldutrqkuiikkxkccnvxkkcdmlvsoududwmszpcrxfyckgdnhxvbhipxailopjpagjtssubjqryszvakdzmqqensqpmlobdohunwmqdvsexcotpmbdnrzjozymmahpvxrfvqjyppkguqeqfjzqquunjucpklshfizqsdsozcfhroomsceknndlakucrsyfkkjeauuhblcwfubtatghwjwylgtixidghdkpwsxvyucwzjovegwuzmdmzdzipapaftthkxcqzhbxzuxdysmydkqxdzoiwvlcllkfqrplmmzlvdafrvujssdjlosjhxrmkolygnmhafjzsoqzzgqixbblfeakrqzcozpfhaldatxdawaencurqlkqmontijupsaxpdzuodecpztnsfvgtxxsnlqhuxojdllylacuknrpelcxlfqrnohnzynmvmrymndpraehvdzpyqbfcqpoospnnumxvbjkfximgpzfvqkxixcccxkpsbebarqjlnoruguynbqjnsyqatwmxjxkinemdscabmvjepayznbsnrcvwnsiwciaeyurrzxspaggwtbcwcgcxygzyvaqsiuemwqfigqoiupelteadpkmtrjzsfcmtdnbxviagxxxjfnyxkfpoypzewzqyjwynavgvxkdmmklbupcvswmfgjszfttodzpjjzdpmcuprzkzgkawsjttitwsmlfzveqpsnreurbxktxbnhopghituwzdqreqixlrjyflambpwtvauuqwdiihxdvvgmudztstoasyznviqclgrkfooxiaftlfgafcvqzqvvgqnteruftasazvqqltgyezacmjolusiyfaptyaugprvrmdadpkkqjzzyuuiajdojrwnvcsyrbilfkwsthlatekadqwrbexptujelyjlhckgzodzegnwavhjtzdhgngaygylxunyitnnbhfzrcqrbedkydkotnlaxxivreyqzprtoqifuglaneimgtltxtvabeyhowyhvercjscsjtcvbihorrcprfhwlkfplfvxvwydlqlfxksvjspyzjbsituzbawcushnrpbqtsybjuwdhwmilcmyhocyafcxdwmtnjdgribthfgjcvvdgggmevoujuxebbdgjymfcssrocrfefzhjajcaggezbvzfnajjrdsswvnlfhmbemxiibvbbisrpdaecvgexdhanenawkxfdesvqvjkxtjwfprmcqgizqjakkvbqszfexgrkhqsbvpagulmkeltzlldflzlwfluxjtrzgyturuvngqsdwwjvnvesingccnmgydwpxqxszhwcpiilkwtlbkoqkgxidomcmwhpbispyntpwydcljijcxpgbdquiangjcsgqerddvwbasrokfwttzcwvxwctzqqeizkazcvilyaqiwpgtresrvmmsovmngszwxqgsicuavurejrxqhqhdogizjyrgtscrswuqduludhpqoaqgoremhcwothfxtwamlpbjuxknaootmgrgqwsfviauavltgjmnewwampfkxgnptbtwlvephmqjitrbqizhkxpbltpirxvkbeeytrjfjyvfkxpoydfopgkfogrbwkruirmpztudohctalqnlwjnjgxhrnlcfrtbnaaxheaedkhubxlylvxgjicisijslypysyyrxhveknlpswcveggzypxtouftekmktmbhzmjxijgegrelttuzxgxeontzylnmadtygmgfrwjdxavcahctbfrwgpizvygtrilecddmihbacugavkpqxunwtzxakssyfqixpqsohxpznknrptsijjvfrqwafhzqedbevybbcwlrcinnqmonigwmmcfteehdjnpmivzarzjlsswdzwdyojliqyxasploqcuowsnepemzsrasnrwxudbozpiaawvfkmiibjpbmjptavrzjaxvqdpdbjavhzmdyoooqwaxualbxbbwlnxyclxrmrrsbczbelkgmszbtarhjzyptkhtmekbigdduhfuqokqabgbdwoyewvsdbgthcxlefmcglnkghioigivsyirhtrmtcygsvboykbbxrrxqtghtztwmguoojyskkovsswxuqsbevfxexaddndjamwnmwlqfniuzvgwddwaaktkuhsmegkklakvcphurrctywbwnwuzfhrsqpmcxrcqopiyhrrtoyrlgkeyusswndesokqsjhsyveioagkkiftwwkdwmastkhvnvnpxyrjvuavwbahtzanolkzviqhduoznybklsipqquhvhevpyfnbixivtaqdsfi"
		);

        const auto actual = permutation_in_string::checkInclusion( input.first, input.second );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    class generate_subsets_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( generate_subsets_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 2, 3 };

        const auto actual = subsets::generate( input );
        const auto expected = std::vector<std::vector<int>>
        {
			{},
        	{ 1 },
        	{ 2 },
        	{ 1, 2 },
        	{ 3 },
        	{ 1, 3 },
        	{ 2, 3 },
        	{ 1, 2, 3 }
        };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( generate_subsets_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 4 };

        const auto actual = subsets::generate( input );
        const auto expected = std::vector<std::vector<int>>
        {
			{},
        	{ 1 },
        	{ 2 },
        	{ 1, 2 },
        	{ 3 },
        	{ 1, 3 },
        	{ 2, 3 },
        	{ 1, 2, 3 },
        	{ 4 },
        	{ 1, 4 },
        	{ 2, 4 },
        	{ 1, 2, 4 },
        	{ 3, 4 },
        	{ 1, 3, 4 },
        	{ 2, 3, 4 },
        	{ 1, 2, 3, 4 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( generate_subsets_tests, case3 )
    {
        const auto input = std::vector<int>{ 5, 4, 3 };

        const auto actual = subsets::generate( input );
        const auto expected = std::vector<std::vector<int>>
        {
			{},
        	{ 5 },
        	{ 4 },
        	{ 5, 4 },
        	{ 3 },
        	{ 5, 3 },
        	{ 4, 3 },
        	{ 5, 4, 3 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( generate_subsets_tests, case4 )
    {
        const auto input = std::vector<int>{ 1 };

        const auto actual = subsets::generate( input );
        const auto expected = std::vector<std::vector<int>>
        {
            {},
            { 1 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( generate_subsets_tests, case5 )
    {
        const auto input = std::vector<int>{ 5, 3, 1, 2, 6 };

        const auto actual = subsets::generate( input );
        const auto expected = std::vector<std::vector<int>>
        {
			{},
        	{ 5 },
        	{ 3 },
        	{ 5, 3 },
        	{ 1 },
        	{ 5, 1 },
        	{ 3, 1 },
        	{ 5, 3, 1 },
        	{ 2 },
        	{ 5, 2 },
        	{ 3, 2 },
        	{ 5, 3, 2 },
        	{ 1, 2 },
        	{ 5, 1, 2 },
        	{ 3, 1, 2 },
        	{ 5, 3, 1, 2 },
        	{ 6 },
        	{ 5, 6 },
        	{ 3, 6 },
        	{ 5, 3, 6 },
        	{ 1, 6 },
        	{ 5, 1, 6 },
        	{ 3, 1, 6 },
        	{ 5, 3, 1, 6 },
        	{ 2, 6 },
        	{ 5, 2, 6 },
        	{ 3, 2, 6 },
        	{ 5, 3, 2, 6 },
        	{ 1, 2, 6 },
        	{ 5, 1, 2, 6 },
        	{ 3, 1, 2, 6 },
        	{ 5, 3, 1, 2, 6 }
        };

        EXPECT_EQ( actual, expected );
    }

    class pivot_index_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( pivot_index_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 7, 3, 6, 5, 6 };

        const auto actual = pivot_index::find_pivot( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pivot_index_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 7, 3, 6, 5, 6, 3, 4, 11, 1, 3, 2 };

        const auto actual = pivot_index::find_pivot( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pivot_index_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 7, 3, 6, 5, 6, 3, 4, 11, 1, 3, 2, 3, 1, 3, 5, 7, 8, 9 };

        const auto actual = pivot_index::find_pivot( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pivot_index_tests, case4 )
    {
        const auto input = std::vector<int>{ 1, 2 };

        const auto actual = pivot_index::find_pivot( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pivot_index_tests, case5 )
    {
        const auto input = std::vector<int>{ -1, -1, -1, -1, -1, -1 };

        const auto actual = pivot_index::find_pivot( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    class binary_string_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( binary_string_sum_tests, ps_case1 )
    {
        const auto input1 = std::vector<int>
        {
            1, 0, 1, 0, 1
        };

        const auto actual = binary_strings_sum::num_subarrays_with_sum1( input1, 2 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( binary_string_sum_tests, ps_case2 )
    {
        const auto input1 = std::vector<int>
        {
            0, 0, 0, 0, 0
        };

        const auto actual = binary_strings_sum::num_subarrays_with_sum1( input1, 0 );
        const auto expected = 15;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( binary_string_sum_tests, ps_case3 )
    {
        const auto input1 = std::vector<int>
        {
            1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0
        };

        const auto actual = binary_strings_sum::num_subarrays_with_sum1( input1, 2 );
        const auto expected = 17;

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( binary_string_sum_tests, sw_case1 )
    {
        const auto input1 = std::vector<int>
        {
            1, 0, 1, 0, 1
        };
    	
        const auto actual = binary_strings_sum::num_subarrays_with_sum2( input1, 2 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( binary_string_sum_tests, sw_case2 )
    {
        const auto input1 = std::vector<int>
        {
            0, 0, 0, 0, 0
        };

        const auto actual = binary_strings_sum::num_subarrays_with_sum2( input1, 0 );
        const auto expected = 15;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( binary_string_sum_tests, sw_case3 )
    {
        const auto input1 = std::vector<int>
        {
            1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0
        };

        const auto actual = binary_strings_sum::num_subarrays_with_sum2( input1, 2 );
        const auto expected = 17;

        EXPECT_EQ( actual, expected );
    }

    class compare_version_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( compare_version_tests, case1 )
    {
        const auto actual = compare_versions::compare_version( "1.01", "1.001" );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( compare_version_tests, case2 )
    {
        const auto actual = compare_versions::compare_version( "1.0", "1.0.0" );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( compare_version_tests, case3 )
    {
        const auto actual = compare_versions::compare_version( "0.1", "1.1" );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( compare_version_tests, case4 )
    {
        const auto actual = compare_versions::compare_version( "1.0.1", "1" );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    class prod_except_self_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( prod_except_self_tests, case1 )
    {
        const auto actual = prod_except_self::product_except_self( { 1, 2, 3, 4 } );
        const auto expected = std::vector<int>{ 24, 12, 8, 6 };

        EXPECT_EQ( actual, expected );
    }

    class longest_without_repeats_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( longest_without_repeats_tests, case1 )
    {
        const auto input1 = "abcabcbb";
        const auto actual = longest_without_repeats::length_of_longest_substring( input1 );
        const auto expected = 3;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_without_repeats_tests, case2 )
    {
        const auto input1 = "bbbbb";
        const auto actual = longest_without_repeats::length_of_longest_substring( input1 );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_without_repeats_tests, case3 )
    {
        const auto input1 = "pwwkew";
        const auto actual = longest_without_repeats::length_of_longest_substring( input1 );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    class trapping_rain_water_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( trapping_rain_water_tests, case1 )
    {
        const auto input1 = std::vector<int>{ 0,1,0,2,1,0,1,3,2,1,2,1 };
        const auto actual = trapping_rain_water::trap( input1 );

        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class tree_sum_closest_sw_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( tree_sum_closest_sw_tests, case1 )
    {
        auto input1 = std::pair<std::vector<int>, int>
    	(
            { -1, 2, 1, -4 },
            1
        );

        const auto actual = tree_sum_closest_sw::three_sum_closest( input1.first, input1.second );

        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }
	
}