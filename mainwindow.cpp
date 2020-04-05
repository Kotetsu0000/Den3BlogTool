#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Output_clicked()
{
//--------------------------------------------以下、出力ボタンが押されたときに実行される部分--------------------------------------------//

    //チェックボックスと書いた人の選択確認

    QString Author = ui->comboBox_Author->currentText();    //現在のコンボボックスの選択肢取得。

    QString Title = ui -> lineEdit_Title -> text();             //タイトル

    QString Overview = ui->plainTextEdit_Overview -> toPlainText();    //概要

    QString Word = ui->lineEdit_Word-> text();      //検索ワード

    if(Title=="")     //タイトルが入力されていない場合以下を実行しこの関数を終了する。
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("タイトルを入力してください。"));
        return;
    }

    if(Overview=="")     //概要が入力されていない場合以下を実行しこの関数を終了する。
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("概要を入力してください。"));
        return;
    }

    if(Author=="選択してください。")     //書いた人が選択されていない場合以下を実行しこの関数を終了する。
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("書いた人を選択してください。"));
        return;
    }

    if(ui->checkBox_HTML->checkState() != Qt::Checked
    && ui->checkBox_3DCG->checkState() != Qt::Checked
    && ui->checkBox_Game->checkState() != Qt::Checked
    && ui->checkBox_Other->checkState() != Qt::Checked)     //カテゴリが1つも選択されていない場合以下を実行しこの関数を終了する。
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("カテゴリをを1つ以上選択してください。"));
        return;
    }

    QString Sit_Den3 = "芝浦工業大学電子計算機研究会";

    QString Sit_Description = "芝浦工業大学公認サークル電子計算機研究会のHPです。";

    QString Sit_Keywords = "芝浦工業大学,電子計算機研究会,電算,Den3";

//---------------------------------------------------------------------------------------------------------------------


    QFile index("出力/index.html");

    if (!index.open(QIODevice::WriteOnly))//書込みのみでオープンできたかチェック
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("index.htmlを開けませんでした。"));
        return;
    }

    QTextStream out(&index);
    out << "<!DOCTYPE html>"<<endl;
    out << "<html lang=\"ja\">"<<endl;
    out << "<head>"<<endl;
    out << "<meta charset=\"UTF-8\">"<<endl;
    out << "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"<<endl;
    out << "<title>"<<Title<<" | "<< Sit_Den3 <<"-Den3</title>"<<endl;
    out << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"<<endl;
    out << "<meta name=\"description\" content=\""<< Sit_Description <<"\">"<<endl;
    out << "<meta name=\"keywords\" content=\""<< Sit_Keywords <<"\">"<<endl;
    out << "<link rel=\"stylesheet\" href=\"/set/css/style.css\">"<<endl;
    out << "<link rel=\"icon\" href=\"/set/image/icon.png\" />"<<endl;
    out << "<link rel=\"stylesheet\" href=\"/set/css/prism_okaidia.css\">"<<endl;
    out << "<head prefix=\"og: http://ogp.me/ns# website: http://ogp.me/ns/website#\">"<<endl;
    out << "<meta property=\"og:type\" content=\"website\" />"<<endl;
    out << "<meta property=\"og:url\" content=\"http://den3.sakura.ne.jp/\" />"<<endl;
    out << "<meta property=\"og:image\" content=\"http://den3.sakura.ne.jp/set/image/blogicon.png\" />"<<endl;
    out << "<meta name=\"twitter:card\" content=\"summary_large_image\" />"<<endl;
    out << "<meta name=\"twitter:site\" content=\"@sit_densan\" />"<<endl;
    out << "<meta name=\"twitter:creator\" content=\"@sit_densan\" />"<<endl;
    out << "<meta property=\"og:title\" content=\""<< Title << "\">"<<endl;
    out << "<meta name=\"description\" content=\""<< Overview <<"\">"<<endl;
    out << "<meta property=\"og:description\" content=\""<< Overview <<"\" />"<<endl;
    out << "</head>"<<endl;
    out << "<body class=\"preload\">"<<endl;
    out << "<div id=\"header\"></div>"<<endl;
    out << "<div id=\"contents\">"<<endl;
    out << "<div id=\"main\">"<<endl;
    out << "<div id=\"mainload\"></div>"<<endl;
    out << "<div id=\"markdown_content\" src=\"main.md\"></div>"<<endl;
    out << "<div id=\"comment\"></div>"<<endl;
    out << "</div>"<<endl;
    out << "<div id=\"sub\">"<<endl;
    out << "<div id=\"memberexplain\"></div>"<<endl;
    out << "<div id=\"seriesload\"></div>"<<endl;
    out << "<div id=\"subload\"></div>"<<endl;
    out << "</div>"<<endl;
    out << "</div>"<<endl;
    out << "<div id=\"footer\"></div>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/style.js\"></script>"<<endl;
    out << "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/headmenu.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/header/activity_diary.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/footer.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/comment.js\"></script>"<<endl;
    out << "<script src=\"https://cdn.jsdelivr.net/npm/marked/marked.min.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"/set/js/markdwon.js\"></script>"<<endl;
    out << "<script type=\"text/javascript\" src=\"main.js\"></script>"<<endl;
    out << "<script async src=\"https://platform.twitter.com/widgets.js\" charset=\"utf-8\"></script>"<<endl;
    out << "<!-- Global site tag (gtag.js) - Google Analytics -->"<<endl;
    out << "<script async src=\"https://www.googletagmanager.com/gtag/js?id=UA-154875486-1\"></script>"<<endl;
    out << "<script>"<<endl;
    out << "window.dataLayer = window.dataLayer || [];"<<endl;
    out << "function gtag() { dataLayer.push(arguments); }"<<endl;
    out << "gtag(\"js\", new Date());"<<endl;
    out << "gtag(\"config\", \"UA-154875486-1\");"<<endl;
    out << "</script>"<<endl;
    out << "</body>"<<endl;

    // ファイルを閉じる
    index.close();

//-------------------------------------------------------------------------------------------------------------------

    QFile mains("出力/main.js");

    if (!mains.open(QIODevice::WriteOnly))//書込みのみでオープンできたかチェック
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("main.htmlを開けませんでした。"));
        return;
    }
    QTextStream js_out(&mains);
    js_out << "$(function(){"<<endl;
    js_out << "    $(\"#mainload\").load(\"main.html\");"<<endl;
    js_out << "    $(\"#subload\").load(\"sub.html\");"<<endl;
    js_out << "    $(\"#seriesload\").load(\"../series.html\");"<<endl;
    if(Author=="丁字路の人"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/16/01/explain.html\");"<<endl;}
    else if(Author=="考えるリンゴ"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/17/01/explain.html\");"<<endl;}
    else if(Author=="トイレの紙"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/01/explain.html\");"<<endl;}
    else if(Author=="pine"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/02/explain.html\");"<<endl;}
    else if(Author=="TT"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/03/explain.html\");"<<endl;}
    else if(Author=="kirby"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/04/explain.html\");"<<endl;}
    else if(Author=="TOEICアンチ"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/05/explain.html\");"<<endl;}
    else if(Author=="ライム"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/06/explain.html\");"<<endl;}
    else if(Author=="音無"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/18/07/explain.html\");"<<endl;}
    else if(Author=="こてつ"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/19/01/explain.html\");"<<endl;}
    else if(Author=="Satan"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/19/02/explain.html\");"<<endl;}
    else if(Author=="しでん"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/19/03/explain.html\");"<<endl;}
    else if(Author=="五字きのこ"){js_out << "    $(\"#memberexplain\").load(\"/set/blog/19/04/explain.html\");"<<endl;}
    js_out << "});"<<endl;

    // ファイルを閉じる
    mains.close();
//-------------------------------------------------------------------------------------------------------------------

    QFile data("出力/data.json");

    if (!data.open(QIODevice::WriteOnly))//書込みのみでオープンできたかチェック
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("data.jsonを開けませんでした。"));
        return;
    }
    QTextStream data_out(&data);
    data_out << "{" <<endl;
    data_out << "  \"Categories\":\"";
    if(ui->checkBox_HTML->checkState() == Qt::Checked){data_out << "HTML,";}
    if(ui->checkBox_3DCG->checkState() == Qt::Checked){data_out << "3DCG,";}
    if(ui->checkBox_Game->checkState() == Qt::Checked){data_out << "Game,";}
    if(ui->checkBox_Other->checkState() == Qt::Checked){data_out << "Other,";}
    data_out << "\"," <<endl;
    data_out << "  \"Author\":\"" << Author << "\"," <<endl;
    data_out << "  \"Search\":\"" << Word << "\"," <<endl;
    data_out << "  \"Image\":\"\"," <<endl;
    data_out << "  \"New\":\"\"," <<endl;
    data_out << "  \"Title\":\"" << Title << "\"," <<endl;
    data_out << "  \"Date\":\"\"" <<endl;
    data_out << "}" <<endl;

    // ファイルを閉じる
    data.close();
//-------------------------------------------------------------------------------------------------------------------

    QFile table("出力/table.txt");

    if (!table.open(QIODevice::WriteOnly))//書込みのみでオープンできたかチェック
    {
        QMessageBox::critical(this, tr("電子計算機研究会ブログ作成ツール"), tr("table.txtを開けませんでした。"));
        return;
    }
    QTextStream table_out(&table);
    table_out << "            <tr>" <<endl;
    table_out << "                <td class=\"categories\">";
    if(ui->checkBox_HTML->checkState() == Qt::Checked){table_out << "html,";}
    if(ui->checkBox_3DCG->checkState() == Qt::Checked){table_out << "cg,";}
    if(ui->checkBox_Game->checkState() == Qt::Checked){table_out << "game,";}
    if(ui->checkBox_Other->checkState() == Qt::Checked){table_out << "other,";}
    table_out <<"</td>" <<endl;
    table_out << "                <td class=\"author\">"<< Author <<"</td>" <<endl;
    table_out << "                <td class=\"search\">"<< Word <<"</td>" <<endl;
    table_out << "                <td class=\"image\">" <<endl;
    table_out << "                    <a href=\"/activity_diary/\">" <<endl;
    table_out << "                        <span class=\"image\" style=\"background-image: url('/activity_diary/##/images/thumbnail.png')\"></span>" <<endl;
    table_out << "                    </a>" <<endl;
    table_out << "                </td>" <<endl;
    table_out << "                <td class=\"new\"><span class=\"newicon\">NEW</span></td>" <<endl;
    table_out << "                <td class=\"title\"><a href=\"/activity_diary/\">"<< Title <<"</a></td>" <<endl;
    table_out << "                <td class=\"date\"></td>" <<endl;
    table_out << "            </tr>" <<endl;


    // ファイルを閉じる
    table.close();
//-------------------------------------------------------------------------------------------------------------------
    QMessageBox::information(this, tr("電子計算機研究会ブログ作成ツール"), tr("出力に成功しました"));

}













