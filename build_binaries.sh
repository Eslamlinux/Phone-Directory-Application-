#!/bin/bash

# Phone Directory v1.0.1 - Binary Builder Script
# هذا السكريبت ينشئ الملفات الثنائية المطلوبة

echo "🔨 بناء الملفات الثنائية للمشروع..."
echo "========================================"

# تنظيف الملفات القديمة
echo "🧹 تنظيف الملفات القديمة..."
make clean 2>/dev/null || rm -rf obj phone_directory

# إنشاء مجلد obj إذا لم يكن موجود
mkdir -p obj

echo "⚙️  تجميع الملفات..."

# تجميع الملفات واحد تلو الآخر مع عرض التقدم
echo "   📄 تجميع main.cpp..."
g++ -std=c++17 -Wall -Isrc -c main.cpp -o obj/main.o

echo "   📄 تجميع setup.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/setup.cpp -o obj/setup.o

echo "   📄 تجميع datatree.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/datatree.cpp -o obj/datatree.o

echo "   📄 تجميع addNumber.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/addNumber.cpp -o obj/addNumber.o

echo "   📄 تجميع readList.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/readList.cpp -o obj/readList.o

echo "   📄 تجميع deleteAllContacts.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/deleteAllContacts.cpp -o obj/deleteAllContacts.o

echo "   📄 تجميع The_counter.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/The_counter.cpp -o obj/The_counter.o

echo "   📄 تجميع utils.cpp..."
g++ -std=c++17 -Wall -Isrc -c src/utils.cpp -o obj/utils.o

echo "🔗 ربط الملفات لإنشاء الملف التنفيذي..."
g++ -std=c++17 -Wall -Isrc -o phone_directory obj/main.o obj/setup.o obj/datatree.o obj/addNumber.o obj/readList.o obj/deleteAllContacts.o obj/The_counter.o obj/utils.o

# التحقق من نجاح البناء
if [ -f "phone_directory" ]; then
    echo "✅ تم إنشاء الملفات الثنائية بنجاح!"
    echo ""
    echo "📊 الملفات المنشأة:"
    echo "   🎯 phone_directory ($(ls -lh phone_directory | awk '{print $5}'))"
    echo "   📁 obj/ directory with $(ls obj/ | wc -l) object files"
    echo ""
    echo "🚀 يمكنك الآن تشغيل البرنامج بالأمر:"
    echo "   ./phone_directory"
    echo ""
    echo "📦 لإضافة الملفات لـ Git:"
    echo "   git add phone_directory obj/"
    echo "   git commit -m 'Add binary files for v1.0.1'"
    echo "   git push"
else
    echo "❌ فشل في إنشاء الملف التنفيذي!"
    echo "تأكد من وجود جميع الملفات المصدرية."
    exit 1
fi