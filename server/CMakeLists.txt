# 実行プログラムの指定
LIST (APPEND exec_PROGRAMS
    server.cpp
)

# プロジェクト外のライブラリの指定
LINK_DIRECTORIES(
    ${Boost_LIBRARY_DIRS}
)


# ビルド
FOREACH (source_file ${exec_PROGRAMS})
    # GET_FILENAME_COMPONENT コマンド
    #  第1引数: 変数名、第2: パス, 第3: (以下)
    #  (第3)
    #     DIRECTORY: ディレクトリのパスDIRECTORY
    #     NAME     : ファイル名
    #     EXT      : 拡張子
    #     NAME_WE  : 拡張子を除いたファイル名
    #     ABSOLUTE : 絶対パス
    GET_FILENAME_COMPONENT (source_file_we ${source_file} NAME_WE) #変数に.cppを除いたファイル名を設定
    ADD_EXECUTABLE (
        ${source_file_we}
        ${source_file}
    )

    # # リンクライブラリの指定用変数の用意
    LIST (APPEND MY_LINK_LIBRARIES
        # ${Boost_LOG_LIBRARY}
        # ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        # ${Boost_IOSTREAMS_LIBRARY}
        # ${Boost_PROGRAM_OPTIONS_LIBRARY}
        # ${Boost_TIMER_LIBRARY}
        # ${Boost_FILESYSTEM_LIBRARY}
        # ${Boost_SYSTEM_LIBRARY}
        # ${CMAKE_THREAD_LIBS_INIT}
        ${OPENSSL_LIBRARIES}
        crypto
    )

    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

    # リンクするライブラリ指定
    TARGET_LINK_LIBRARIES (${source_file_we}
        ${MY_LINK_LIBRARIES}
    )
    IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        SET_PROPERTY (TARGET ${source_file_we} APPEND_STRING PROPERTY COMPILE_FLAGS "-std=c++14 -Wall -g")
    ENDIF ()
ENDFOREACH ()
