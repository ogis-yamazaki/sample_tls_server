CMAKE_MINIMUM_REQUIRED (VERSION 3.11.0)
PROJECT (cpp_tls_server)

# 変数 BOOST_EXPECTED_INCLUDE に Boost.Expected のヘッダファイルパスを設定
IF ("${BOOST_EXPECTED_INCLUDE}" STREQUAL "")
    SET (BOOST_EXPECTED_INCLUDE "${CMAKE_SOURCE_DIR}/expected/include")
ENDIF ()

# SET (Boost_USE_MULTITHREADED      ON)

# パッケージを探索
# (だいたい次のような変数が設定される。XXXにパッケージ名)
#  XXX_FOUND
#  XXX_INCLUDE_DIRSまたはXXX_INCLUDES
#  XXX_LIBRARIESまたはXXX_LIBS
#  XXX_DEFINITIONS
FIND_PACKAGE (Boost 1.67.0 COMPONENTS log log_setup thread iostreams program_options timer filesystem system)
FIND_PACKAGE (Threads)
FIND_PACKAGE (OpenSSL)
# FIND_PACKAGE (ZLIB)

# # 変数 BEAST_INCLUDE に beast のヘッダファイルパスを設定(Boost 1.66 以下の場合)
# IF ("${BEAST_INCLUDE}" STREQUAL "")
#     IF (${Boost_VERSION} LESS 106600)
#         SET (BEAST_INCLUDE "${CMAKE_SOURCE_DIR}/external/external/mqtt_cpp/external/beast/include")
#     ENDIF ()
# ENDIF ()


# # スタティックビルド指定時の設定
# IF (MSGPUB_STATIC_BUILD)
#     SET (CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)       # remove -Wl,-Bdynamic
#     SET (CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
#     SET (CMAKE_SHARED_LIBRARY_C_FLAGS)         # remove -fPIC
#     SET (CMAKE_SHARED_LIBRARY_CXX_FLAGS)
#     SET (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)    # remove -rdynamic
#    SET (CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

#     SET (CMAKE_FIND_LIBRARY_SUFFIXES .a)
#     SET (CMAKE_EXE_LINKER_FLAGS "-static")

#     SET (Boost_USE_STATIC_LIBS        ON) # only find static libs
# ELSE ()
#     SET (CMAKE_CXX_FLAGS "-DBOOST_LOG_DYN_LINK ${CMAKE_CXX_FLAGS}")
# ENDIF ()

# インクルードパスを指定する
INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}/include/
    ${Boost_INCLUDE_DIR}
    # ${BEAST_INCLUDE}
    #${OPENSSL_INCLUDE_DIR}
)

# サブディレクトリ定義
ADD_SUBDIRECTORY (server)
