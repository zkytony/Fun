/**
 * Created by kaiyu on 9/12/15.
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class IChingStripper {

    static String[] guaNames = {"乾","坤","屯","蒙","需","讼","师","比",
            "小畜","履","泰","否","同人","大有","谦","豫","随","蛊","临",
            "观","噬嗑","贲","剥","复","无妄","大畜","颐","大过","坎","离",
            "咸","恒","遁","大壮","晋","明夷","家人","睽","蹇","解","损",
            "益","夬","姤","萃","升","困","井","革","鼎","震","艮","渐",
            "归妹","丰","旅","巽","兑","涣","节","中孚","小过","既济","未济"};

    Map<Integer, List<String>> guaCiMap;
    static final String base_path = "./resource/";


    public IChingStripper(String guaFileName) throws FileNotFoundException {
        guaCiMap = new HashMap<Integer, List<String>>();

        Scanner s = new Scanner(new File(base_path + guaFileName));

        int guaNumber = 0; // from 0
        List<String> guaCi = new ArrayList<String>();

        while (s.hasNextLine()) {
            String line = s.nextLine();
            if (line.equals("--")) {
                // required: format of each Gua in input file should be
                // GuaCi
                // TuanCi
                // YaoCi (six lines)
                if (guaNumber == 0 || guaNumber == 1) {
                    reverseWithin(guaCi, 2, guaCi.size() - 2); // reverse the order of YaoCi; Qian, Kun has extra
                } else {
                    reverseWithin(guaCi, 2, guaCi.size() - 1); // reverse the order of YaoCi
                }
                guaCiMap.put(guaNumber, guaCi);
                guaCi = new ArrayList<String>();
                guaNumber++;
            } else {
                guaCi.add(line);
            }
        }
    }

    public boolean hasGuaCiFor(int n) {
        return guaCiMap.containsKey(n);
    }


    public String bulkHtmlForAll() {
        String result = "";
        for (int i = 0; i < 64; i++) {
            result += bulkHtmlForOne(i) + "\n";
        }
        return result;
    }

    public String bulkHtmlForOne(int n) throws IllegalStateException {
        if (!hasGuaCiFor(n)) {
            throw new IllegalStateException("Not Gua Ci for No." + (n+1));
        }

        String guaIndex = "" + (n+1);
        if (n + 1 < 10) {
            guaIndex = "0" + guaIndex;
        }

        String result = "";
        result += "<!-- Project begins ======================= -->";
        result += "<div class=\"project\" id=\"gua-" + n + "\">";

        result += "<div class=\"projectThumbnail\">";
        result += "<svg class=\"thumbnailMask\"></svg>";
        result += "<div class=\"projectThumbnailHover\">";
        result += "<h4>" + guaNames[n] + "</h4>";
        result += "</div>";
        result += "<img src=\"images/projects/gua-" + guaIndex + ".svg.png\" alt=\"gua " + guaIndex + "\" class=\"thumbnailImage\" />";
        result += "<h2 class=\"guaName\">" + guaNames[n] + "</h2>";
        result += "</div>";

        result += "<div class=\"projectInfo\">";
        result += "<h4>" + guaCiMap.get(n).get(0) + "</h4>";  // title
        result += "<p>";

        String yaoCi = "";
        for (int i = 2; i < guaCiMap.get(n).size(); i++) {
            yaoCi += guaCiMap.get(n).get(i) + "<br>";
        }
        result += yaoCi;

        result += "</p>";
        result += "<ul>";
        result += "<li>" + guaCiMap.get(n).get(1) + "</li>";
        result += "</ul>";
        result += "</div>";

        result += "</div>";
        result += "<!-- Project ends =================================================================== -->";

        return result;
    }

    public static void reverseWithin(List list, int start, int end) {
        int k = 0;
        for(int i = start; i < start + (end - start)  / 2 + 1; i++) {
            Object temp = list.get(i);
            list.set(i, list.get(end - k));
            list.set(end - k, temp);
            k++;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        IChingStripper tool = new IChingStripper("guas.txt");
        System.out.println(tool.bulkHtmlForAll());
    }
}