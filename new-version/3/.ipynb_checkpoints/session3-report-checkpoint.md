Team Name: `[FILL HERE]`

Student Name of member 1: `[FILL HERE]`
Student No. of member 1: `[FILL HERE]`


- [X] Read Session Contents.

### Section 3.3.1
- [X] Investigate the /proc/ directory
    1. [X] [FILL HERE with an image of files in /proc/ directories. Use ls command.]

![](photo_1_2023-09-05_12-50-28.jpg)

### Section 3.3.2

- [X] Do 5 subtasks from 1 to 5:
    1. [X] [FILL HERE with the content of /proc/version. Use cat command.]

![](photo_2_2023-09-05_12-50-28.jpg)

1. [X] [FILL HERE with the content of two files with non-numeric name other thatn /proc/version.]

![](photo_3_2023-09-05_12-50-28.jpg)

1. [X] [FILL HERE with the program you write for this part (see experiment guide for information).]

cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream version_stream("/proc/version");
  stringstream buffer;
  buffer << version_stream.rdbuf();
  ofstream output("./Linux Version.txt");
  output << buffer.str();
  output.close();
  version_stream.close();
}

1. [X] [FILL HERE with screen capture from your programs execution.]

![](photo_4_2023-09-05_12-50-28.jpg)

1. [X] [FILL HERE with description about, what happens if you try to write a sentence in to /proc/version.]

<div dir="rtl">
این فایل یک فایل رید‌آنلی بوده و نوشتن در آن منجر به دریافت خطا می‌شود
</div>

## Section 3.3.3

- [X] Write (in English or Persian) about each file in /proc/(PID) directory:
1. [FILL HERE with description about cmdline]

<div dir="rtl">
دستوری که برای اجرای برنامه اجرا شده است را نشان می‌دهد (به همراه آرگومان‌هایش)
</div>

1. [FILL HERE with description about environ]

<div dir="rtl">
مقدار متغیر‌های env را نشان می‌دهد که در این برنامه استفاده می‌شوند.
</div>

1. [FILL HERE with description about stat]

<div dir="rtl">
status پروسه را به ما نشان می‌دهد
</div>

1. [FILL HERE with description about status]

<div dir="rtl">
همان بالایی است ولی به صورتی که برای انسان قابل خواندن باشد نشان می‌دهد
</div>

1. [FILL HERE with description about statm]

<div dir="rtl">
اطلاعات مموری پردازه را نشان می‌دهد
</div>

1. [FILL HERE with description about cwd]

<div dir="rtl">
لینک به current working directory
</div>

1. [FILL HERE with description about exe]

<div dir="rtl">
لینک به فایل اجرایی این برنامه
</div>

1. [FILL HERE with description about root]

<div dir="rtl">
لینک به دایرکتوری root این پردازه
</div>

- [X] Place your script for shwoing PID of running porcesses and their name here:
    - [X] [FILL HERE with your script]

bash
ps

<div dir="rtl">
این دستور در اصل اسنپ‌شاتی از کل پروسه‌های موجود در سیستم به ما می‌دهد
که در آن PID و نام کامندی که با آن پروسه شروع شده است را به ما نشان می‌دهد
۲ ستون دیگر نیز دارد که آن‌ها به ترتیب ترمینال مشخص پروسه و دیگری cpu تایمی است که به این پروسه اختصاص داده شده است
</div>

- [X] Place your source code for a program that shows details of a program by receiving PID:
    - [X] [FILL HERE with your source code]


cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string cmd = "/proc/" + s + "/cmdline";
    ifstream cmd_stream(cmd);
    std::cout << cmd_stream.rdbuf();
    cmd_stream.close();

    string environ = "/proc/" + s + "/environ";
    ifstream environ_stream(environ);
    std::cout << environ_stream.rdbuf();
    environ_stream.close();

    string statm = "/proc/" + s + "/statm";
    ifstream statm_stream(statm);
    std::cout << statm_stream.rdbuf();
    statm_stream.close();

    string status = "/proc/" + s + "/status";
    ifstream status_stream(status);
    std::cout << status_stream.rdbuf();
    status_stream.close();

    return 0;
}

<div dir="rtl">
برنامه یک PID دریافت می‌کند و به کمک آن فایل‌های موجود در 
فولدر
/proc/PID
را در کنسول پرینت می‌کند تا دیتای مورد نظر را به ما نشان دهد.
</div>


### Section 3.3.4

- [X] Write (in English or Persian) about each file in /proc/ directory:
1. [FILL HERE with description about meminfo]

<div dir="rtl">
خلاصه‌ای از اینکه کرنل چگونه مموری را منیج کرده است
</div>

1. [FILL HERE with description about version]

<div dir="rtl">
اطلاعات ورژن کرنل را به جزئیات در اختیار ما قرار داده است
</div>

1. [FILL HERE with description about uptime]

<div dir="rtl">
این فایل شامل ۲ عدد می‌شود؛ اولی نشان دهنده میزان آپ بودن سیستم به ثانیه است و دومی نشان‌دهنده میزان idle بودن آن به ثانیه.
</div>

1. [FILL HERE with description about stat]

<div dir="rtl">
اطلاعات کلی و آماری کرنل را نشان می‌دهد، به طور مثال نحوه استفاده از cpuها یا swap چگونه است و ...
</div>

1. [FILL HERE with description about mounts]

<div dir="rtl">
به صورت کلی نشان‌دهنده این است که فضای فعلی پردازه چگونه و به کجا و چطور mount شده است.
</div>

1. [FILL HERE with description about net directory (or file)]

<div dir="rtl">
یک فولدر شامل تعداد زیادی فایل و فولدر می‌باشد که مشخص‌کننده لایه نتورک سیستم‌عامل است
</div>

1. [FILL HERE with description about loadavg]

<div dir="rtl">
سه مقدار اولی نشان‌دهنده میانگین لود سیستم است:

برای تعداد جاب‌هایی که در کیو منتظر هستند یا برای جاب‌هایی که پند disk io هستند؛ اولی میانگین ۱ دقیقه اخیر دومی ۵ دقیقه و سومی ۱۵ دقیقه اخیر می‌باشد.

مورد بعدی دو عدد هستند که با / جدا شده است. اولی تعداد پردازه و ترد‌هایی است که الان قابل اجرا می‌باشند دومی نیز نشان‌دهنده پردازه‌ها و ترد‌هایی است که در سیستم وجود دارند.

آخرین مورد هم PID آخرین پردازه ساخته شده توسط سیستم است
</div>

1. [FILL HERE with description about interrupts]

<div dir="rtl">
نشان‌دهنده تعداد اینتراپت‌هایی است که به ازای هر cpu وجود دارد
</div>

1. [FILL HERE with description about ioports]

<div dir="rtl">
نشان‌دهنده لیست دیوایس‌های ورودی و خروجی‌ای است که در حال حاضر به سیستم متصل می‌باشند.
</div>

1. [FILL HERE with description about filesystem]

<div dir="rtl">
به صورت خلاصه نشان‌دهنده این است که کرنل از چه فایل‌سیستم‌هایی پشتیبانی می‌کند.
</div>

1. [FILL HERE with description about cpuinfo]

<div dir="rtl">
به ازای هر پردازنده مشخص می‌کند که چه ساختار و چه مشخصاتی دارد
</div>

1. [FILL HERE with description about cmdline]

<div dir="rtl">
آرگومان‌هایی که موقع بوت کردن کرنل به آن پاس داده شده است.
</div>

- [X] Place your source code for a program that shows details of processor:
    - [X] [FILL HERE with your source code]


cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream cpuinfo_filestream("/proc/cpuinfo");
    stringstream buffer;
    buffer << cpuinfo_filestream.rdbuf();
    string output = buffer.str();
    cpuinfo_filestream.close();

    std::regex model_name_regex("model name(\\s*): (.+)");
    std::smatch model_name_matches;
    if(std::regex_search(output, model_name_matches, model_name_regex)) {
        std::cout << "model name: " << model_name_matches[2].str() << "\n";
    }

    std::regex cpu_freq_regex("cpu MHz(\\s*): (.+)");
    std::smatch cpu_freq_matches;
    if(std::regex_search(output, cpu_freq_matches, cpu_freq_regex)) {
        std::cout << "cpu freq: " << cpu_freq_matches[2].str() << "\n";
    }

    std::regex cache_size_regex("cache size(\\s*): (.+) KB");
    std::smatch cache_size_matches;
    if(std::regex_search(output, cache_size_matches, cache_size_regex)) {
        std::cout << "cache size: " << cache_size_matches[2].str() << "\n";
    }

}

<div dir="rtl">
به کمک رجکس اطلاعات مورد نظر خود را از فایل مورد نظربه دست می‌آوریم
</div>

- [X] Place your source code for a program that shows details of memory management sub-system:
    - [X] [FILL HERE with your source code]

cpp
#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream meminfo_filestream("/proc/meminfo");
    stringstream buffer;
    buffer << meminfo_filestream.rdbuf();
    string output = buffer.str();
    meminfo_filestream.close();
    int mem_free, mem_total;

    std::regex mem_total_regex("MemTotal:(\\s*)(.+) kB");
    std::smatch mem_total_matches;
    if(std::regex_search(output, mem_total_matches, mem_total_regex)) {
        mem_total = stoi(mem_total_matches[2]);
        std::cout << "mem total: " << mem_total << "\n";
    }

    std::regex mem_free_regex("MemFree:(\\s*)(.+) kB");
    std::smatch mem_free_matches;
    if(std::regex_search(output, mem_free_matches, mem_free_regex)) {
        mem_free = stoi(mem_free_matches[2]);
        std::cout << "mem free: " << mem_free << "\n";
    }

    std::cout << "mem used: " << mem_total - mem_free << "\n";
}

<div dir="rtl">
به کمک رجکس مموری کل سیستم و مموری آزاد را از فایل به دست می‌اوریم. 
مسلما مموری استفاده شده همان کل مموری موجود در سیستم منهای مموری آزاد سیستم می‌باشد و کد چنین چیزی را محسابه می‌کند
</div>

- [X] Write your description about five important files at /proc/sys/kernel:
- [X] [FILL HERE with your descript for dmesg_restrict]

<div dir="rtl">
مشخص کننده‌ این است که چه کسی می‌تواند syslog کرنل را ببیند اگر صفر باشد یعنی رستریکشنی وجود ندارد ولی اگر یک باشد یوزر‌هایی که دسترسی دارند می‌توانند اطلاعات را مشاهده کنند
</div>

- [X] [FILL HERE with your descript for panic]

<div dir="rtl">
این فایل به کرنل دسترسی خواندن و نوشتن panic_timeout را می‌دهد اگر صفر باشد کرنل روی panic لوپ می‌زند در غیر این صورت تا مقداری که در فایل مشخص شده است صبر می‌کند و سپس سیستم را ریبوت می‌کند
</div>

- [X] [FILL HERE with your descript for modprobe]

<div dir="rtl">
این فایل نام فایل loader کرنل را در خود ذخیره کرده است
</div>

- [X] [FILL HERE with your descript for sched_rr_timeslice_ms]

<div dir="rtl">
میزان زمان کوانتوم تایم را برای الگوریتم راند رابین مشخص می‌کند. (میلی ثانیه)
</div>

- [X] [FILL HERE with your descript for threads-max]

<div dir="rtl">
مشخص کننده این است که کل سیستم تا چه اندازه می‌تواند ترد ایجاد کند.
</div>

- [X] Write your description about /proc/self file
    - [X] [FILL HERE with your description]

<div dir="rtl">
اگر هر پردازه‌ای وارد این فولدر شود مشخصات /proc/PID خود را در آن بدون دانستن PID خود خواهد دید. در اصل یک لینک به فولدر /proc/PID می‌باشد
</div>

## Source Code Submission

please submit all your codes in a zip file

 - [x] Zip File HERE
[az-3.zip](az-3.zip)