#include <QtCore/qdebug.h>
#include <QtCore/qfile.h>
#include <QtCore/qfileinfo.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qdir.h>
#include <QtCore/QTextStream>
#include <QtCore/QThread>

#include <QtQmlDom/private/qqmldomtop_p.h>
#include <QtQmlDom/private/qqmldomfilewriter_p.h>
#include <QtQmlDom/private/qqmldomoutwriter_p.h>
#include <QtQmlDom/private/qqmldomelements_p.h>
#include <QtQmlDom/private/qqmldomfieldfilter_p.h>

#include <cstdio>
#include <optional>

#include <QCoreApplication>

#include <QtCore/qlibraryinfo.h>
using namespace QQmlJS::Dom;

int main(int argc, char *argv[])
{
    // dumping with no filter takes to much time to finish
    FieldFilter defaultFilter = FieldFilter::defaultFilter();
    //FieldFilter basicFilter = FieldFilter{};

    // Making the Envirionment node
    //  set import path
    QStringList qmltypeDirs = QStringList { QLibraryInfo::path(QLibraryInfo::Qml2ImportsPath) };;
    //  set options
    DomEnvironment::Options options = DomEnvironment::Option::SingleThreaded;
    //  create DomEnvironment
    std::shared_ptr<DomEnvironment> envPtr(new DomEnvironment(qmltypeDirs, options));

    // DomItem from DomEnvironment
    DomItem env(envPtr);

    // Load QML file on the environment
    DomItem qmlFile;
    QString s("Sample.qml");
    env.loadFile(
                s, QString(),
                [&qmlFile](Path path, const DomItem &, const DomItem &newIt) {
                    qDebug() << "Path: " << path;
                    qmlFile = newIt;
                },
                LoadOption::DefaultLoad, DomType::QmlFile);
    envPtr->loadPendingDependencies(env);

    qDebug() << "qmlFile";
    qDebug() << qmlFile.canonicalFilePath();


    qDebug() << "will dump\n";

    QTextStream ts(stdout);
    auto sink = [&ts](QStringView v) {

        ts << v; /* ts.flush(); */
    };
    //qmlFile.dump(sink, 0, filter);
    //env.dump(sink, 0, filter);

    //ts << "\n";
    //ts << qmlFile.fields()[0];

    //DomItem comp = qmlFile.component(GoTo::MostLikely);
    //DomItem comp = qmlFile.fileObject(GoTo::MostLikely);
    //QString key = qmlFile.field(QString("currentItem")).field(QString("components")).fields()[0];

    //QString baseTarget = CppTypeInfo::fromString(target, errorHandler).baseType;

    //DomItem comp = qmlFile.field(QString("currentItem")).field(QString("components"));
    //DomItem comp = qmlFile[QString("currentItem")][QString("components")][QString("")][0]["objects"][0];
    //int size = qmlFile.field(QString("currentItem")).field(QString("components")).size();
    //qDebug() << "size: " << size;

    // QMLFile
    DomItem comp = qmlFile.field(QString("currentItem"));
    comp.dump(sink, 0, defaultFilter);

    /*
    { "~type~":"QmlFile",
      "errors":{
      },
      "canonicalFilePath":"C:/github/LeviPoc/build-QmlDomSample-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/Sample.qml",
      "isValid":true,
      "components":{
        "":[
          { "~type~":"QmlComponent",
            "name":"Sample",
            "enumerations":{
            },
            "objects":[
              { "~type~":"QmlObject",
                "name":"Rectangle",
                "prototypes":[
                  { "~type~":"Reference",
                    "referredObjectPath":"@lookup.type[\"Rectangle\"]",
                    "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.exports[\"Rectangle\"][6]"}
                  }],
                "propertyDefs":{
                },
                "bindings":{
                },
                "methods":{
                  "mySignal":[
                    { "~type~":"MethodInfo",
                      "name":"mySignal",
                      "access":2,
                      "typeName":"",
                      "isReadonly":false,
                      "isList":false,
                      "annotations":[],
                      "parameters":[],
                      "methodType":0
                    }
                  ]
                },
                "children":[
                  { "~type~":"QmlObject",
                    "name":"Text",
                    "prototypes":[
                      { "~type~":"Reference",
                        "referredObjectPath":"@lookup.type[\"Text\"]",
                        "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.exports[\"Text\"][12]"}
                      }],
                    "propertyDefs":{
                    },
                    "bindings":{
                    },
                    "methods":{
                    },
                    "children":[],
                    "annotations":[],
                    "defaultPropertyName":"data"
                  }],
                "annotations":[],
                "defaultPropertyName":"data"
              }],
            "isSingleton":false,
            "isCreatable":true,
            "isComposite":true,
            "attachedTypeName":"",
            "attachedType":{ "~type~":"Reference",
              "referredObjectPath":"",
              "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
            },
            "ids":{
            },
            "subComponents":[]
          }
        ]
      },
      "pragmas":[],
      "imports":[
        { "~type~":"Import",
          "uri":"\"C:/github/LeviPoc/build-QmlDomSample-Desktop_Qt_6_4_0_MinGW_64_bit-Debug\"",
          "version":{ "~type~":"Version",
            "majorVersion":-1,
            "minorVersion":-1,
            "isLatest":false,
            "isValid":false,
            "stringValue":"."
          },
          "implicit":true
        },
        { "~type~":"Import",
          "uri":"QML",
          "version":{ "~type~":"Version",
            "majorVersion":1,
            "minorVersion":0,
            "isLatest":false,
            "isValid":true,
            "stringValue":"1.0"
          },
          "implicit":true
        },
        { "~type~":"Import",
          "uri":"QtQml",
          "version":{ "~type~":"Version",
            "majorVersion":6,
            "minorVersion":0,
            "isLatest":false,
            "isValid":true,
            "stringValue":"6.0"
          },
          "implicit":true
        },
        { "~type~":"Import",
          "uri":"QtQuick",
          "version":{ "~type~":"Version",
            "majorVersion":-2,
            "minorVersion":-2,
            "isLatest":true,
            "isValid":false,
            "stringValue":""
          }
        }]
    }
    */

    // Top Object
    //DomItem topObj = qmlFile[u"currentItem"][u"components"][u""][0][u"objects"][0];
    //DomItem topObj = qmlFile.path(u".currentItem.components")[u""][0][u"objects"][0];
    //topObj.dump(sink, 0, defaultFilter);

    /*
    { "~type~":"QmlObject",
      "name":"Rectangle",
      "prototypes":[
        { "~type~":"Reference",
          "referredObjectPath":"@lookup.type[\"Rectangle\"]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.exports[\"Rectangle\"][6]"}
        }],
      "propertyDefs":{
      },
      "bindings":{
      },
      "methods":{
        "mySignal":[
          { "~type~":"MethodInfo",
            "name":"mySignal",
            "access":2,
            "typeName":"",
            "isReadonly":false,
            "isList":false,
            "annotations":[],
            "parameters":[],
            "methodType":0
          }
        ]
      },
      "children":[
        { "~type~":"QmlObject",
          "name":"Text",
          "prototypes":[
            { "~type~":"Reference",
              "referredObjectPath":"@lookup.type[\"Text\"]",
              "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.exports[\"Text\"][12]"}
            }],
          "propertyDefs":{
          },
          "bindings":{
          },
          "methods":{
          },
          "children":[],
          "annotations":[],
          "defaultPropertyName":"data"
        }],
      "annotations":[],
      "defaultPropertyName":"data"
    }
    */

    // Look up the type
    //DomItem rect = qmlFile.lookupFirst("Rectangle", LookupType::Type);
    //rect.dump(sink, 0, noFilter);

    /*
    { "~type~":"Export",
      "uri":"QtQuick",
      "typeName":"Rectangle",
      "version":{ "~type~":"Version",
        "majorVersion":6,
        "minorVersion":3,
        "isLatest":false,
        "isValid":true,
        "stringValue":"6.3"
      },
      "type":{ "~type~":"Reference",
        "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[0]",
        "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[0]"}
      },
      "isInternal":false,
      "isSingleton":false,
      "exportSource":{ "~type~":"Reference",
        "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
        "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
      }
    }
    */


    // Tracing Rectangle
    // "exports" node helps tracking the link from Rectangle to QQuickRectangle
    //DomItem rect = env[u"qmltypesFileWithPath"][u"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes"][u"currentItem"][u"exports"][u"Rectangle"];
    //DomItem rect = env.path(u"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.exports[\"Rectangle\"]");
    //rect.dump(sink, 0, filter);

    // the last Rectangle is the recent version type
    /*
    [
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":2,
          "minorVersion":0,
          "isLatest":false,
          "isValid":true,
          "stringValue":"2.0"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[6]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[6]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":2,
          "minorVersion":1,
          "isLatest":false,
          "isValid":true,
          "stringValue":"2.1"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[5]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[5]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":2,
          "minorVersion":4,
          "isLatest":false,
          "isValid":true,
          "stringValue":"2.4"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[4]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[4]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":2,
          "minorVersion":7,
          "isLatest":false,
          "isValid":true,
          "stringValue":"2.7"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[3]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[3]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":2,
          "minorVersion":11,
          "isLatest":false,
          "isValid":true,
          "stringValue":"2.11"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[2]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[2]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":6,
          "minorVersion":0,
          "isLatest":false,
          "isValid":true,
          "stringValue":"6.0"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[1]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[1]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      },
      { "~type~":"Export",
        "uri":"QtQuick",
        "typeName":"Rectangle",
        "version":{ "~type~":"Version",
          "majorVersion":6,
          "minorVersion":3,
          "isLatest":false,
          "isValid":true,
          "stringValue":"6.3"
        },
        "type":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[0]",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[0]"}
        },
        "isInternal":false,
        "isSingleton":false,
        "exportSource":{ "~type~":"Reference",
          "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem"}
        }
      }
    ]
    */

    //DomItem qqrect = env.path(u"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"]");
    //qqrect.dump(sink, 0, defaultFilter);

    /*
    [
      { "~type~":"QmltypesComponent",
        "name":"QQuickRectangle",
        "enumerations":{
        },
        "objects":[
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-1539",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[1]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[1]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-1536",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[2]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[2]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-523",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[3]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[3]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-519",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[4]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[4]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-516",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[5]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[5]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-513",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[6]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[6]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickRectangle-512",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[7]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickRectangle\"][0].objects[7]"}
              }],
            "propertyDefs":{
            },
            "bindings":{
            },
            "methods":{
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          },
          { "~type~":"QmlObject",
            "name":"QQuickItem",
            "prototypes":[
              { "~type~":"Reference",
                "referredObjectPath":"@lookup.cppType[\"QQuickItem\"]",
                "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickItem\"][0].objects[0]"}
              }],
            "propertyDefs":{
              "border":[
                { "~type~":"PropertyDefinition",
                  "name":"border",
                  "access":2,
                  "typeName":"QQuickPen",
                  "isReadonly":true,
                  "isList":false,
                  "annotations":[],
                  "isPointer":true,
                  "isFinal":false,
                  "isAlias":false,
                  "isDefaultMember":false,
                  "isRequired":false,
                  "read":"border",
                  "write":"",
                  "bindable":"",
                  "notify":"",
                  "type":{ "~type~":"Reference",
                    "referredObjectPath":"@lookup.type[\"QQuickPen\"]",
                    "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
                  }
                }
              ],
              "color":[
                { "~type~":"PropertyDefinition",
                  "name":"color",
                  "access":2,
                  "typeName":"QColor",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "isPointer":false,
                  "isFinal":false,
                  "isAlias":false,
                  "isDefaultMember":false,
                  "isRequired":false,
                  "read":"color",
                  "write":"setColor",
                  "bindable":"",
                  "notify":"colorChanged",
                  "type":{ "~type~":"Reference",
                    "referredObjectPath":"@lookup.type[\"QColor\"]",
                    "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
                  }
                }
              ],
              "gradient":[
                { "~type~":"PropertyDefinition",
                  "name":"gradient",
                  "access":2,
                  "typeName":"QJSValue",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "isPointer":false,
                  "isFinal":false,
                  "isAlias":false,
                  "isDefaultMember":false,
                  "isRequired":false,
                  "read":"gradient",
                  "write":"setGradient",
                  "bindable":"",
                  "notify":"",
                  "type":{ "~type~":"Reference",
                    "referredObjectPath":"@lookup.type[\"QJSValue\"]",
                    "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
                  }
                }
              ],
              "radius":[
                { "~type~":"PropertyDefinition",
                  "name":"radius",
                  "access":2,
                  "typeName":"double",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "isPointer":false,
                  "isFinal":false,
                  "isAlias":false,
                  "isDefaultMember":false,
                  "isRequired":false,
                  "read":"radius",
                  "write":"setRadius",
                  "bindable":"",
                  "notify":"radiusChanged",
                  "type":{ "~type~":"Reference",
                    "referredObjectPath":"@lookup.type[\"double\"]",
                    "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
                  }
                }
              ]
            },
            "bindings":{
            },
            "methods":{
              "colorChanged":[
                { "~type~":"MethodInfo",
                  "name":"colorChanged",
                  "access":2,
                  "typeName":"",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "parameters":[],
                  "methodType":0
                }
              ],
              "doUpdate":[
                { "~type~":"MethodInfo",
                  "name":"doUpdate",
                  "access":2,
                  "typeName":"",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "parameters":[],
                  "methodType":1,
                  "isConstructor":false
                }
              ],
              "radiusChanged":[
                { "~type~":"MethodInfo",
                  "name":"radiusChanged",
                  "access":2,
                  "typeName":"",
                  "isReadonly":false,
                  "isList":false,
                  "annotations":[],
                  "parameters":[],
                  "methodType":0
                }
              ]
            },
            "children":[],
            "annotations":[],
            "defaultPropertyName":"data"
          }],
        "isSingleton":false,
        "isCreatable":false,
        "isComposite":false,
        "attachedTypeName":"",
        "attachedType":{ "~type~":"Reference",
          "referredObjectPath":"",
          "get":{ "~type~": "Reference", "immediate": true, "referredObjectPath":""}
        },
        "metaRevisions":[
          1539,
          1536,
          523,
          519,
          516,
          513,
          512,
          0],
        "fileName":"private/qquickrectangle_p.h",
        "interfaceNames":[],
        "hasCustomParser":false,
        "valueTypeName":"",
        "extensionTypeName":"",
        "accessSemantics":0
      }
    ]
    */

    // Basic information of QQuickItem
    //DomItem qqitem = env.path(u"$top.qmltypesFileWithPath[\"C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes\"].currentItem.components[\"QQuickItem\"][0].objects");
    //qqitem.dump(sink, 0, filter);


    // @lookup works in the qmlFile not in env
    //DomItem qobject = qmlFile.path(u"@lookup.type[\"Rectangle\"]");
    //DomItem qobject = qmlFile.lookupFirst("Rectangle", LookupType::Type);
    //qobject.dump(sink, 0, noFilter);

    //ts << comp.canonicalPath().toString();
    Qt::endl(ts).flush();

    return 0;
}
