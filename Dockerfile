# ベースイメージとして公式の GCC イメージを使用
FROM gcc:latest

# 作業ディレクトリを作成
WORKDIR /app

# ソースコードをコンテナにコピー
COPY ./main.c++ .

# main.c++をコンパイルして実行可能ファイルmyappを作成
# RUN g++ -o myapp main.c++

# コンパイルしたプログラムを実行
CMD ["/bin/bash"]
