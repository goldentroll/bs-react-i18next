type i18next = (string, option(Js.Dict.t(string))) => ReasonReact.reactElement;

/* most keys are reactElement but sometimes we need to make them string */
external toString: ReasonReact.reactElement => string = "%identity";


/*
 [@bs.val] external t: (string, option(Js.Dict.t(string))) => ReasonReact.reactElement = "t";
 [@bs.val] external ts: (string, option(Js.Dict.t(string))) => string = "t";
 */
/*
 external t: (string, option(Js.Dict.t(string))) => string = "t";
 */

/* external t: string => string = "t(%identity)"; */
/* [@bs.val] external t: (a:string) => string = [%bs.raw {|t(a)|}]; */
/*
 [@bs.val] external t: string => string = "t";

 let t = [%bs.raw {| t("alert.madeAComment") |}];
 */
