# c++ LightsOut について

c++で実装したLightsOutです。

## UIの対応状況
- CUI
  - 標準入出力
- GUI
  - wxWidgets

# ビルド方法
## 基本のビルド方法

 以下のコマンドをインストールしてください。
- make
- cmake
- ninja

このディレクトリで `make` を実行します。  
エラーが出なければ成功です。

## GUIのビルド方法

wxWidgetsをインストールしてください。  
このディレクトリで `make build_wx` を実行します。  
エラーが出なければ成功です。

## 注意点
実行ファイルは上書きされるので、最後にビルドされたものだけ実行できます。

# 実行方法
ビルド後、このディレクトリで `make run` を実行します。

# ライセンス
gawsel c++ LightsOut は Apache License 2.0 の下で配布されています。  
詳細は、本ディレクトリの LICENSE ファイルをご覧ください。